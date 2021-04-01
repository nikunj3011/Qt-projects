#ifndef Card_hpp
#define Card_hpp

#include <string>
#include <set>
#include <map>
#include <iostream>



enum class Suit {CLUB, DIAMOND, HEART, SPADE};
enum class Face {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
enum class CardColor {Black, Red};
class Card
{
public:
    Card(Face f, Suit s) : suit(s), face(f), _matched(false), _flipped(false) {}
    std::string toString() const;

    CardColor getColor()const;
    Suit getSuit()const;
    Face getFace()const;

    bool isMatched()const{return _matched;}
    bool isFlipped()const{return _flipped;}

    void flip();
    void setMatched(bool matched);

    int getMatchValue(Card otherCard);

    const Suit suit;
    const Face face;

private:
    bool _matched;
    bool _flipped;

public:
    static const std::set<Suit> suits;
    static const std::set<Face> faces;

    static const std::map<Face, std::string>  faceNames;
    static const std::map<Suit, std::string>  suitNames;
};


inline bool operator==(const Card& lhs, const Card& rhs){
    return ((lhs.face == rhs.face)&&(lhs.suit == rhs.suit));
}
inline bool operator< (const Card& lhs, const Card& rhs){
    if (lhs.face < rhs.face) return true;
    if ((lhs.face == rhs.face) && (lhs.suit < rhs.suit)) return true;
    return false;
}
inline bool operator!=(const Card& lhs, const Card& rhs){return !operator==(lhs,rhs);}
inline bool operator> (const Card& lhs, const Card& rhs){return  operator< (rhs,lhs);}
inline bool operator<=(const Card& lhs, const Card& rhs){return !operator> (lhs,rhs);}
inline bool operator>=(const Card& lhs, const Card& rhs){return !operator< (lhs,rhs);}

std::ostream& operator<<(std::ostream& os, Card& c);

using CardPtr = std::shared_ptr<Card>;

#endif /* Card_hpp */
