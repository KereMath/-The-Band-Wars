#include "kpop.h"
#include "metal.h"
#include "rock.h"
#include "jazz.h"

int KPopBand::play(MusicBand *other) {
    double C=0.5;
    double K = 0.2; 
    if (dynamic_cast<KPopBand*>(other)) {C = 2.0;} 
    int score = (get_fan_count() + 0.1 * get_talent() * get_energy()) * C;
    set_energy(get_energy() - get_energy() * K);
    return score;
}

void KPopBand::rehearse(void) {
    double K = 0.2; 
    int T = 0; 
    set_energy(get_energy() - (0.5 * K) * get_energy());
    set_talent(get_talent() + T);
}