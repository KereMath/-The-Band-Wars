#include "metal.h"
#include "kpop.h"
#include "rock.h"
#include "jazz.h"

int MetalBand::play(MusicBand *other) {
    double C; 
    double K = 0.16; 
    if (dynamic_cast<KPopBand*>(other)) {
        C = 0.5;
    } else if (dynamic_cast<MetalBand*>(other)) {
        C = 1.0;
    } else if (dynamic_cast<RockBand*>(other)) {
        C = 1.5;
    } else{
        C = 1.1;
    }
    int score = (get_fan_count() + 0.1 * get_talent() * get_energy()) * C;
    set_energy(get_energy() - get_energy() * K);
    return score;
}

void MetalBand::rehearse(void) {
    double K = 0.16; 
    int T = -5; 
    set_energy(get_energy() - (0.5 * K) * get_energy());
    set_talent(get_talent() + T);
}