#include "jazz.h"
#include "kpop.h"
#include "metal.h"
#include "rock.h"

int JazzBand::play(MusicBand *other) {
    double C;
    double K = 0.06; 
    if (dynamic_cast<KPopBand*>(other)) {
        C = 0.5;
    } else if (dynamic_cast<MetalBand*>(other)) {
        C = 1.3;
    } else{C=0.7;}
    int score = (get_fan_count() + 0.1 * get_talent() * get_energy()) * C;
    set_energy(get_energy() - get_energy() * K);
    return score;
}
void JazzBand::rehearse(void) {
    double K = 0.06; 
    int T = 5; 
    set_energy(get_energy() - (0.5 * K) * get_energy());
    set_talent(get_talent() + T);
}