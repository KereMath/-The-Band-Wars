#include "tournament_round.h"

TournamentRound::TournamentRound() { }

TournamentRound::TournamentRound(std::list<MusicBand*> _bands) : bands(_bands) { }

TournamentRound::TournamentRound(std::vector<MusicBand*> _bands) : bands(_bands.begin(), _bands.end()) { }

std::size_t TournamentRound::size() { return bands.size(); }

TournamentRound& TournamentRound::operator=(TournamentRound&& other) {
    if (this == &other) {
        return *this;
    } else {
        bands.clear();
        for (auto band = other.bands.begin(); band != other.bands.end(); ++band) {
            bands.push_back(std::move(*band));
        }
        other.bands.clear();
    }
    return *this;
}

TournamentRound& TournamentRound::get_next_round() {
    std::list<MusicBand*> results;
    while (bands.size() > 0) {
        MusicBand* band1 = bands.front();
        bands.pop_front();
        if(bands.size() > 0) {
            MusicBand* band2 = bands.back();
            bands.pop_back();
            int score1 = band1->play(band2);
            int score2 = band2->play(band1);
            if (score1 >= score2) {
                results.push_back(band1);
                int fandiff = std::min(score1 - score2, band2->get_fan_count());
                band1->set_fan_count(band1->get_fan_count() + fandiff);
                band2->set_fan_count(band2->get_fan_count() - fandiff);
            } 
            else {
                results.push_back(band2);
                int fandiff = std::min(score2 - score1, band1->get_fan_count());
                band2->set_fan_count(band2->get_fan_count() + fandiff);
                band1->set_fan_count(band1->get_fan_count() - fandiff);
            }
        } 
        else{
            results.push_back(band1);
        }
    }
    bands = results;
    return *this;
}


std::ostream& operator<< (std::ostream &os, TournamentRound &other) {
    if (!other.bands.empty()) {
        std::list<MusicBand*>::iterator it = other.bands.begin();
        while (it != other.bands.end()) {
            MusicBand* currentBand = *it;
            std::string bandName = currentBand->get_name();
            os << bandName;
            if (std::next(it) != other.bands.end()) {
                os << "\t";
            }
    ++it;
        }
    }
    return os;
}
