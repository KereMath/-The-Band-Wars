#include "rock.h"
#include "kpop.h"
#include "metal.h"
#include "jazz.h"

int RockBand::play(MusicBand *other) {
    double C; 
    double K = 0.1; 

    if (dynamic_cast<KPopBand*>(other)) {
        C = 0.5;
    } else if (dynamic_cast<MetalBand*>(other)) {
        C = 1.4;
    } else if (dynamic_cast<RockBand*>(other)) {
        C = 1.0;
    } else{
        C = 0.8;
    }

    // Calculate the score
       
    int score = (get_fan_count() + 0.1 * get_talent() * get_energy()) * C;

    // Update the energy
    set_energy(get_energy() - get_energy() * K);

    return score;
   
}
void RockBand::rehearse(void) {
    double K = 0.1; // energy usage percentage
    int T = 10; // talent change

    // Update the energy
    set_energy(get_energy() - (0.5 * K) * get_energy());

    // Update the talent
    set_talent(get_talent() + T);
}