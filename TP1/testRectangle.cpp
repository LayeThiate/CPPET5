#include "square.hpp"


int main(int argc, char *argv[]) {

    std::cout << "~~~~~~~~~~~ TEST OF RECTANGLE ~~~~~~~~~~~~\n\n";
    Rectangle *rect = new Rectangle(3, 4);

    std::cout << "rectangle [" << rect->getLength() << "," << rect->getWidth() << "],  surface = " << rect->surface() << std::endl;

    Rectangle copy = *rect;
    std::cout << "After affect constructor et set length\n ";

    copy.setLength(4);
    std::cout << "rectangle [" << rect->getLength() << "," << rect->getWidth() << "],  surface = " << rect->surface() << std::endl;
    std::cout << "rectangle [" << copy.getLength() << "," << copy.getWidth() << "],  surface = " << copy.surface() << std::endl;

    std::cout << copy << std::endl;

    std::cout << "\nAfter swap" << std::endl;
    Rectangle r = Rectangle(2, 9);
   // boost::swap(r, rect);

    std::cout << "\n~~~~~~~~~~~ TEST OF SQUARE ~~~~~~~~~~~~\n\n";
    Square sq = Square(3);
    Square *ss = new Square(2);
    Rectangle *sr = new Square(3);

    std::cout << "square [" << sr->getLength() << "," << sr->getWidth() << "],  surface = " << sr->surface() << std::endl;

    *sr = *ss;

    sr->setLength(5);
    std::cout << "square [" << sr->getLength() << "," << sr->getWidth() << "],  surface = " << sr->surface() << std::endl;
    std::cout << "square [" << ss->getLength() << "," << ss->getWidth() << "],  surface = " << ss->surface() << std::endl;

}