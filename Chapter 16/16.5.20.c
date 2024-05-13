enum {NORTH, SOUTH, EAST, WEST} direction;

int main(void)
{
    int x, y;

    direction = NORTH;

    switch(direction) {
        case NORTH:
            y--;
            break;
        case SOUTH:
            y++;
            break;
        case EAST:
            x++;
            break;
        case WEST:
            x--;
            break;
        default:
            break;
    }
}