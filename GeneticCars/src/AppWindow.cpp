#include "AppWindow.h"
#include "MainController.h"

AppWindow::~AppWindow()
{
}

AppWindow::AppWindow(PMainController c, const float& width, const float& height, const int& bitsPerPixel, const std::string& name)
{
    window_.create(sf::VideoMode(width, height, bitsPerPixel), name, sf::Style::Close | sf::Style::Titlebar);
    default_view_.setCenter(sf::Vector2f(width / 2, height / 2));
    default_view_.setSize(sf::Vector2f(width, height));
    window_.setView(default_view_);
    setUpGUI();
    controller_ = c;
    running_=false;
}

// --------metody [get] -----------
sf::RenderWindow & AppWindow::getWindow()
{
    return window_;
}

sf::View & AppWindow::getView()
{
    return sim_view_;
}

void AppWindow::setUpGUI()
{
    auto upper_left_frame = sfg::Frame::Create( "Parametry populacji" );
    auto lower_left_frame = sfg::Frame::Create( "Parametry symulacji" );
    auto simulation_frame = sfg::Frame::Create();
    auto list_frame = sfg::Frame::Create( "Lista najlepszych osobnikow" );

    auto main_box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
    auto lower_box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
    auto upper_box = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL,5.f);
    auto upper_left_vertical_box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.f);
    auto lower_left_vertical_box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.f);
    auto left_vertical_box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.f);

    auto upper_left_horizonal_box1 = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 5.f);
    size_entry_ = sfg::Entry::Create("6");
    upper_left_horizonal_box1->Pack(sfg::Label::Create("Rozmiar populacji:"),false);
    upper_left_horizonal_box1->Pack(size_entry_);
    upper_left_vertical_box->Pack(upper_left_horizonal_box1,false);
    auto upper_left_horizonal_box2 = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 5.f);
    rate_entry_ = sfg::Entry::Create("0.1");
    upper_left_horizonal_box2->Pack(sfg::Label::Create("Wspolczynnik mutacji:"),false);
    upper_left_horizonal_box2->Pack(rate_entry_);
    upper_left_vertical_box->Pack(upper_left_horizonal_box2,false);
    auto upper_left_horizonal_box3 = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 5.f);
    max_gen_entry_ = sfg::Entry::Create("30");
    upper_left_horizonal_box3->Pack(sfg::Label::Create("Maksymalne pokolenie:"),false);
    upper_left_horizonal_box3->Pack(max_gen_entry_);
    upper_left_vertical_box->Pack(upper_left_horizonal_box3,false);

    auto lower_left_horizonal_box1 = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 5.f);
    gravity_entry_ = sfg::Entry::Create("5.0");
    lower_left_horizonal_box1->Pack(sfg::Label::Create("Wspolczynnik grawitacji:"),false);
    lower_left_horizonal_box1->Pack(gravity_entry_);
    lower_left_vertical_box->Pack(lower_left_horizonal_box1,false);
    auto lower_left_horizonal_box2 = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 5.f);
    steep_entry_ = sfg::Entry::Create("100");
    lower_left_horizonal_box2->Pack(sfg::Label::Create("Stromosc trasy:"),false);
    lower_left_horizonal_box2->Pack(steep_entry_);
    lower_left_vertical_box->Pack(lower_left_horizonal_box2,false);
    auto lower_left_horizonal_box3 = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 5.f);
    length_entry_ = sfg::Entry::Create("1000");
    lower_left_horizonal_box3->Pack(sfg::Label::Create("Liczba odcinkow trasy:"),false);
    lower_left_horizonal_box3->Pack(length_entry_);
    lower_left_vertical_box->Pack(lower_left_horizonal_box3,false);

    upper_left_frame->Add(upper_left_vertical_box);
    lower_left_frame->Add(lower_left_vertical_box);

    left_vertical_box->Pack(upper_left_frame,false);
    left_vertical_box->Pack(lower_left_frame,false);
    auto run_button = sfg::Button::Create("Uruchom symulacje");
    run_button->GetSignal( sfg::Widget::OnLeftClick ).Connect( std::bind( &AppWindow::onRunButtonClick, this ) );
	auto stop_button = sfg::Button::Create("Przerwij symulacje");
	stop_button->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&AppWindow::stopSimulation, this));
    left_vertical_box->Pack(run_button,false);
	left_vertical_box->Pack(stop_button, false);

    auto scroll_window = sfg::ScrolledWindow::Create();
    best_list_box_ = sfg::Box::Create( sfg::Box::Orientation::VERTICAL );
    scroll_window->SetScrollbarPolicy( sfg::ScrolledWindow::HORIZONTAL_AUTOMATIC );
    scroll_window->AddWithViewport( best_list_box_ );
    //scrolledwindow->SetRequisition( sf::Vector2f( 500.f, 100.f ) );
    list_frame->Add(scroll_window);
    left_vertical_box->Pack(list_frame,true,true);

    upper_box->Pack(left_vertical_box,false);
    upper_box->Pack(simulation_frame,true,true);

    lower_box->Pack(sfg::Separator::Create(sfg::Separator::Orientation::HORIZONTAL),false);
    info_label_ = sfg::Label::Create();
    lower_box->Pack(info_label_,false);

    main_box->Pack(upper_box);
    main_box->Pack(lower_box,false);

    auto gui_window = sfg::Window::Create(sfg::Window::Style::BACKGROUND);
    gui_window->SetRequisition(static_cast<sf::Vector2f>( window_.getSize()));
    gui_window->Add(main_box);
    desktop_.Add(gui_window);

    sim_view_.setCenter(0,0);
    sim_view_.setSize(simulation_frame->GetAllocation().width, simulation_frame->GetAllocation().height);
    sim_view_.setViewport(
                sf::FloatRect(
                    (simulation_frame->GetAbsolutePosition().x / window_.getSize().x),
                    (simulation_frame->GetAbsolutePosition().y / window_.getSize().y),
                    (simulation_frame->GetAllocation().width / window_.getSize().x),
                    (simulation_frame->GetAllocation().height / window_.getSize().y)*0.98
                    ));
}

void AppWindow::drawAll(PDrawing drawing)
{
	window_.setView(sim_view_);
	window_.pushGLStates();
	sf::RectangleShape background(sf::Vector2f(sim_view_.getSize().x *2, sim_view_.getSize().y * 2));
	background.setPosition(sim_view_.getCenter().x-background.getSize().x/2, sim_view_.getCenter().y - background.getSize().y / 2);
	background.setFillColor(sf::Color::White);
	window_.draw(background);
	window_.draw(drawing->getLine());
	for (sf::CircleShape circle : drawing->getCircles()) {
		window_.draw(circle);
	}
	for (sf::ConvexShape polygon : drawing->getPolygons()) {
		window_.draw(polygon);
	}
	window_.popGLStates();
	window_.display();
	window_.setView(default_view_);
}


void AppWindow::updateGUI()
{
    desktop_.Update(clock_.restart().asSeconds());
    window_.resetGLStates();
    window_.clear(sf::Color::White);
    sfgui_.Display(window_);
    if(!running_)
        window_.display();
}

void AppWindow::updateState(const float& best, const float& current, const float& track_length)
{
    updateInfo(std::string("Dlugosc trasy: " + boost::lexical_cast<string>(static_cast<int>(track_length)) + " m | " +
		"Pozycja najlepszego osobnika: " + boost::lexical_cast<string>(static_cast<int>(best)) + " m | "  +
		" Pozycja obserwowanego osobnika: " + boost::lexical_cast<string>(static_cast<int>(current)) + " m |"  ));
}
void AppWindow::updateFollow(const float& follow)
{
    sim_view_.setCenter(sf::Vector2f(follow * SCALE, 300));
}

void AppWindow::handleEvent(sf::Event e)
{
    desktop_.HandleEvent(e);
}

void AppWindow::updateInfo(const std::string& info)
{
    info_label_->SetText(info);
}

void AppWindow::updateList(const int& gen, const float& m)
{
    best_list_box_->Pack(sfg::Label::Create(std::string(
                            "Pokolenie " + boost::lexical_cast<string>(gen+1) + " , Dystans " +
                            boost::lexical_cast<string>(m) + " m")),false);
}

void AppWindow::onRunButtonClick()
{
    if(!running_)
    {
        clearList();
        int size,max_gen,steep,length;
        float gravity,rate;
        updateInfo(" ");
        try
        {
            size = boost::lexical_cast<int>(std::string(size_entry_->GetText()));
            rate = boost::lexical_cast<float>(std::string(rate_entry_->GetText()));
            max_gen = boost::lexical_cast<int>(std::string(max_gen_entry_->GetText()));
            gravity = boost::lexical_cast<float>(std::string(gravity_entry_->GetText()));
            steep = boost::lexical_cast<int>(std::string(steep_entry_->GetText()));
            length = boost::lexical_cast<int>(std::string(length_entry_->GetText()));
        }
        catch(const boost::bad_lexical_cast& e)
        {
            updateInfo("Wprowadzono niepoprawne wartosci parametrow!");
            return;
        }
        if(size < 0)
            size = -size;
        if(rate<MUTATION_RATE_MIN)
            rate=MUTATION_RATE_MIN;
        if(rate>MUTATION_RATE_MAX)
            rate=MUTATION_RATE_MAX;
        if(max_gen < 0)
            max_gen = -max_gen;
        if(gravity < 0.0)
            gravity = -gravity;
        if(steep < 0)
            steep = -steep;
        if(length < 0)
            length = -length;
        controller_->setSize(size);
        controller_->setRate(rate);
        controller_->setMaxGen(max_gen);
        controller_->setSimulation(boost::make_shared<PhysSimulation>());
        controller_->getSimualation()->setWorldParams(gravity,1.0,60,8,3);
        controller_->getSimualation()->setTrackParams(steep, 300, 100,length);
        controller_->getSimualation()->getPopulation()->setVelocity(10.0f);
        controller_->createAll();

        running_=true;
    }
}

void AppWindow::stopSimulation()
{
    if(running_)
    {
        running_=false;
        controller_->getSimualation().reset();
    }
}

bool AppWindow::isRunning()
{
    return running_;
}

void AppWindow::clearList()
{
    best_list_box_->RemoveAll();
}
