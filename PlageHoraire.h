#ifndef PLAGE_HORAIRE_H
#define PLAGE_HORAIRE_H

#include <iostream>
#include <set>

class PlageHoraire {
public:
    PlageHoraire(int debut, int fin) : m_debut(debut), m_fin(fin) {}

    int getDebut() const { return m_debut; }
    int getFin() const { return m_fin; }

    bool estIncluseDans(const PlageHoraire& autrePlage) const {
        return m_debut >= autrePlage.getDebut() && m_fin <= autrePlage.getFin();
    }

    bool estEnIntersectionAvec(const PlageHoraire& autrePlage) const {
        return m_fin > autrePlage.getDebut() && m_debut < autrePlage.getFin();
    }

    std::set<PlageHoraire> soustraction(const PlageHoraire& autrePlage) const {
        std::set<PlageHoraire> result;
        if (estEnIntersectionAvec(autrePlage)) {
            if (m_debut < autrePlage.getDebut()) {
                result.emplace(m_debut, autrePlage.getDebut());
            }
            if (m_fin > autrePlage.getFin()) {
                result.emplace(autrePlage.getFin(), m_fin);
            }
        }
        else {
            result.insert(*this);
        }
        return result;
    }

    bool operator<(const PlageHoraire& autrePlage) const {
        if (m_debut < autrePlage.m_debut) {
            return true;
        }
        else if (m_debut > autrePlage.m_debut) {
            return false;
        }
        else {
            return m_fin < autrePlage.m_fin;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const PlageHoraire& plage);

private:
    int m_debut;
    int m_fin;
};

std::ostream& operator<<(std::ostream& os, const PlageHoraire& plage) {
    os << plage.getDebut() << "-" << plage.getFin();
    return os;
}

#endif // PLAGE_HORAIRE_H
