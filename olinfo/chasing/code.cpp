#include <bits/stdc++.h>
using namespace std;

int main() {
    int dx, dy, ds;
    cin >> dx >> dy >> ds;
    int bx, by, bs;
    cin >> bx >> by >> bs;
    char dir;
    cin >> dir;

    if (bs == 0) {
        // per qualche motivo non funziona quando bs = 0, quindi ho isolato questo caso.
        cout << (abs(dx - bx) + abs(dy - by) + ds - 1) / ds << endl;
        // il comando "return 0" termina il programma.
        return 0;
    }

    // ruoto / flippo il sistema di riferimento in modo che la palla non va verso destra
    int temp;
    if (dir == 'U') {
        temp = dx;
        dx = dy;
        dy = -temp;

        temp = bx;
        bx = by;
        by = -temp;
    }
    if (dir == 'L') {
        dx = -dx;
        dy = -dy;

        bx = -bx;
        by = -by;
    }
    if (dir == 'D') {
        temp = dx;
        dx = -dy;
        dy = temp;

        temp = bx;
        bx = -by;
        by = temp;
    }
    
    // spostare il cane sulla y della palla.
    double diff_tempo = (double)abs(by - dy) / (double)ds;
    double bx1 = (double) bs * diff_tempo + bx;

    double dx1 = (double)dx;
    double dy1 = (double)dy;
    double by1 = (double)by;

    double tempo;
    if (dx1 < bx1) {
        if (bs >= ds) {
            tempo = -1;
            diff_tempo = 0;
        }
        else {
            double A = bx1 - dx1;
            double B = ds - bs;
            tempo = A / B;
        }
    }
    else {
        double A = dx1 - bx1;
        double B = ds + bs;
        tempo = A / B;
    }

    cout << ceil(tempo + diff_tempo) << endl;
}
