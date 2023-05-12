#include"setting.h"
// #include<locale>

// khởi tạo mặc định
Setting::Setting(){

    _username1 = "username1";
    _font.loadFromFile(PATH_FONT);
    _username1Display.setFont(_font);
    _username1Display.setFillColor(Color::Black);
    _username1Display.setString(_username1);
    _username1Display.setCharacterSize(SETTING_CHARACTER_SIZE);
    _username1Display.setPosition(POSITION_SETTING_NAME1);

    _username2 = "username2";
    _username2Display.setFont(_font);
    _username2Display.setFillColor(Color::Black);
    _username1Display.setString(_username2);
    _username2Display.setCharacterSize(SETTING_CHARACTER_SIZE);
    _username2Display.setPosition(POSITION_SETTING_NAME2);

    _minutes = "10";
    _time.setFont(_font);
    _time.setFillColor(Color::Black);
    _time.setString(_minutes);
    _time.setCharacterSize(SETTING_CHARACTER_SIZE);
    _time.setPosition(POSITION_SETTING_TIME);
}

void Setting::draw(RenderWindow &window){

    // tạo texture và sprite cho back ground
    Texture textureBackground ;
    textureBackground.loadFromFile(PATH_IMAGE_MENU_BACKGROUD);
    Sprite background;
    background.setTexture(textureBackground);

// vẽ các hình chữ nhật và các chữ lên khi bấm vào nút setting
    //vẽ hình chữ nhật lớn
    sf::RectangleShape rect(sf::Vector2f(300.f, 300.f));
    rect.setFillColor(sf::Color::Black);
    rect.setPosition(250,200);
    
    // vẽ chữ username 1
    Text user1;
    user1.setFont(_font);
    user1.setFillColor(Color::White);
    user1.setString("USER NAME 1");
    user1.setCharacterSize(20);
    user1.setPosition(250,200);

    // vẽ ô để điền vào
    sf::RectangleShape rect1(sf::Vector2f(290.f, 33.f));
    rect1.setFillColor(sf::Color::White);
    rect1.setPosition(255,230);

    // vẽ chữ username2
    Text user2;
    user2.setFont(_font);
    user2.setFillColor(Color::White);
    user2.setString("USER NAME 2");
    user2.setCharacterSize(20);
    user2.setPosition(250,300);

    // vẽ ô để điền vào
    sf::RectangleShape rect2(sf::Vector2f(290.f, 33.f));
    rect2.setFillColor(sf::Color::White);
    rect2.setPosition(255,330);

    // vẽ chữ time
    Text text_Time;
    text_Time.setFont(_font);
    text_Time.setFillColor(Color::White);
    text_Time.setString("_TIME");
    text_Time.setCharacterSize(20);
    text_Time.setPosition(250,400);

    // vẽ ô để điền vào
    sf::RectangleShape rect3(sf::Vector2f(290.f, 33.f));
    rect3.setFillColor(sf::Color::White);
    rect3.setPosition(255,430);

    // vẽ chữ play
    Text play;
    play.setFont(_font);
    play.setFillColor(Color::Black);
    play.setString("PLAY");
    play.setCharacterSize(20);
    play.setPosition(410,560);

    // vẽ nút play
    sf::RectangleShape rect4(sf::Vector2f(100.f, 40.f));
    rect4.setFillColor(sf::Color::White);
    rect4.setPosition(380,550);

    // khởi tạo giá trị
    sf::Clock clock;
    int click1 = 0;
    int click2 = 0;
    int click3 = 0;

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            // xử lý nút tắt
            if (event.type == sf::Event::Closed){
                window.close();
            }

            // xử lý khi bấm chuột   
            if (event.type == sf::Event::MouseButtonPressed)
            {
                
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    // bật click1 khi bấm vào ô điển tên username1
                    if(rect1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
                        click1 = 1;
                        click2 = 0;
                        click3 = 0;
                    }

                    // bật click2 khi bấm vào ô điền tên username2
                    else if(rect2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
                        click2 = 1;
                        click1 = 0;
                        click3 = 0;
                    }

                    // bật click3 khi bấm vào ô điền tên username3
                    else if(rect3.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
                        click2 = 0;
                        click1 = 0;
                        click3 = 1;
                    }

                    // khi bấm vào nút play
                    else if(rect4.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        return;
                    
                    // khi bấm vào đâu đó thì tắt hết các click
                    else {
                        click1 = click2 = click3 = 0;
                    }
                }
                
            }

            // xử lý khi điền tên username1
            if(event.type == Event::TextEntered && click1 == 1){
                if (std::isprint(event.text.unicode) && _username1.length() <= 26)
                    _username1 += event.text.unicode;
            }
            
            // xử lý khi điền tên username2
            if(event.type == Event::TextEntered && click2 == 1){
                if (std::isprint(event.text.unicode) && _username2.length() <= 26)
                    _username2 += event.text.unicode;
            }

            // xử lý khi điền tên username3
            if(event.type == Event::TextEntered && click3 == 1){
                if ( event.text.unicode >= '0' && event.text.unicode <= '9' && _minutes.length() <= 3)
                    _minutes += event.text.unicode;
            }

            // xử lý khi bấm vào nút đặc biệt
            if(event.type == Event::KeyPressed){

                // nút xóa
                if(event.key.code == Keyboard::BackSpace && click1 == 1)
                    if (!_username1.empty())
                        _username1.pop_back();
                if(event.key.code == Keyboard::BackSpace && click2 == 1)
                    if(!_username2.empty())
                        _username2.pop_back();
                if(event.key.code == Keyboard::BackSpace && click3 == 1)
                    if(!_minutes.empty())
                        _minutes.pop_back();
                
                // nút enter
                if (event.key.code == sf::Keyboard::Return) {
                        click1 = 0; 
                        click2 = 0;
                        click3 = 0;
                }
            }
        }
        
        // tạo hiệu ứng nhấp nháy
        static sf::Time text_effect__time;
        static bool show_cursor;
        text_effect__time += clock.restart();
        if (text_effect__time >= sf::seconds(0.5f))
        {
            show_cursor = !show_cursor;
            text_effect__time = sf::Time::Zero;
        }

        // tạo hiệu ứng nhấp nháy
        if(click1 == 1) _username1Display.setString(_username1 + (show_cursor ? '_' : ' '));
        else _username1Display.setString(_username1);
        if(click2 == 1) _username2Display.setString(_username2 + (show_cursor ? '_' : ' '));
        else _username2Display.setString(_username2);
        if(click3 == 1) _time.setString(_minutes + (show_cursor ? '_' : ' '));
        else _time.setString(_minutes);


        window.clear();
        window.draw(background);

        window.draw(rect);
        window.draw(rect1);
        window.draw(user1);
        window.draw(_username1Display);

        window.draw(user2);
        window.draw(rect2);
        window.draw(_username2Display);

        window.draw(text_Time);
        window.draw(rect3);
        window.draw(_time);

        window.draw(rect4);
        window.draw(play);
        window.display();
    }
}