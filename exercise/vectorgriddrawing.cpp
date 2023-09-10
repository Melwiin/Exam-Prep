#include <iostream>

#define GRID_SIZE 5

class Vector2i {
public:
    int x, y;
    Vector2i(int x = 0, int y = 0) : x(x), y(y) {}
};

class Grid {
private:
    char grid[GRID_SIZE][GRID_SIZE];
public: 
    Grid() {
        for(int i = 0; i < GRID_SIZE; i++)
            for (int j = 0; j < GRID_SIZE; j++)
                grid[i][j] = 'o';
    }
    ~Grid() {
        std::cout << "Object destroyed. " << this << std::endl;
    }

    void setPixel(const Vector2i& coords, const char& value) {
        try {
            if(coords.x >= GRID_SIZE || coords.x < 0) throw "Out of index x coordinate.";
            if(coords.y >= GRID_SIZE || coords.y < 0) throw "Out of index y coordinate.";
            grid[coords.x][coords.y] = value;
        }catch(char const* e) {
            std::cerr << e << std::endl;
        }
    }

    void Render() { 
        for(int i = 0; i < GRID_SIZE; i++) {
            std::cout << std::endl;
            for (int j = 0; j < GRID_SIZE; j++)
                std::cout << grid[i][j];
        }
        std::cout << std::endl;
    }
};

int main()
{
    Grid* grid = new Grid();

    // Set pixels:
    grid->setPixel(Vector2i(1, 1), 5);

    grid->Render();

    delete grid;

    return 0;
}
