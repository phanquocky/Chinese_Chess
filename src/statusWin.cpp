#include"statusWin.h"

void StatusWin::draw(sf::RenderWindow &window, int status){

    // load các texture win, continues, defeat    
    Texture textureWin;
    textureWin.loadFromFile(PATH_IMAGE_WIN);
    Texture textureContinue;
    textureContinue.loadFromFile(PATH_IMAGE_CONTINUE);
    Texture textureDefeat;
    textureDefeat.loadFromFile(PATH_IMAGE_DEFEAT);

    // tạo ra các sprite 
    Sprite win;
    win.setPosition(POSITION_WIN); 
    Sprite continues;
    continues.setPosition(POSITION_CONTINUE);
    continues.setTexture(textureContinue);

    // status = 1 thì sprite là win, else thì sprite là defeat
    if(status == 1){
        win.setTexture(textureWin);
    }
    else win.setTexture(textureDefeat);


    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){

            // xử lý nút tắt
            if(event.type == Event::Closed) 
                window.close();
            
            // xử lý khi bấm nút continue
            if(event.type == Event::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left){
                    if(continues.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        return;
                }
            }

        }

        // vẽ 
        window.draw(win);
        window.draw(continues);
        window.display();
    }

}