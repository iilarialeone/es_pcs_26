#pragma once
#include <concepts>
#include <ostream>
#include <iostream>
#include <numeric>

template<typename I> requires std::integral<I>
class Rational{
    I num_;
    I den_;
    //^ sono privati e non accessibili da fuori nè per leggerli e nè per scriverli

    // funzioni private (di default)
    void set_nan(){
        this->num_ = 0;
        this->den_ = 0;
    }

    void set_inf(bool is_pos){
        this->den_ = 0;
        this->num_ = 1;
        if (! is_pos) this->num_ = -1; 
    }

    public:
        //costruttore di default
        Rational() : num_(0), den_(1) {}

        //costruttore con i parametri
        Rational(I num, I den) : num_(num), den_(den) {}


        //Definisco i metodi getter per ottenere i valori dei parametri
        I num() const { //const vuol dire che il metodo non modifica i parametri della classe
            return num_;
        }

        I den() const {
            return den_;
        }

        //Definisco i metodi per l'operational overload
        friend std::ostream& operator << (std::ostream& stream, const Rational<I>& rational) {
            
            if(rational.num()== 0 && rational.den()==0) stream << "NaN"; //Se ho 0/0 ho un not a number
            
            else if(rational.num()!=0 && rational.den()==0){ //Se ho n/0 ho infinito
                if(rational.num()<0) stream << "-"; //Gestisco il - nel caso di numeri negativi
                stream << "Inf";
            }

            else if(rational.num()==0) stream << "0"; //Se il numeratore è 0 allora non avrò 0/n ma 0 e basta

            else{
                I mcd = std::gcd(rational.num(), rational.den());
                if(rational.num()*rational.den()<0) stream << "-"; //Anche in questo caso gestisco il -

                stream << std::abs(rational.num())/mcd << "/" << std::abs(rational.den())/mcd;
            }
            return stream;
        }
        
        //Metodo per l'incremento
        Rational<I> operator+=(const Rational<I>& other) {
            if((den_==0 && num_==0) || (other.den()==0 && other.num()==0)) this->set_nan(); //NaN sommato a qualsiasi cosa dà NaN

            else if(den_ == 0 && other.den()==0){ //se entrambi i den sono 0 gestisco, perchè avrei due +-Inf
                if(num_ * other.num() < 0) this->set_nan(); //se i num sono discordi avrei +Inf-Inf = NaN

                else this->set_inf(num_ > 0); //Altrimenti +Inf+Inf oppure -Inf-Inf 
            }

            else if(den_ !=0 && other.den()==0) this->set_inf(other.num() > 0);
            else if(den_ ==0 && other.den()!=0) this->set_inf(num_ > 0);

            else{
                this->num_ = num_ * other.den() + other.num()*den_;
                this->den_ = den_ * other.den();
            } 
            return *this;
        } //Non semplifico perchè lo farò una volta stampato

        Rational<I> operator+(const Rational<I>& other) {
            Rational sum = *this;
            sum += other;
            return sum;
        }

        Rational<I> operator-=(const Rational<I>& other) {
            Rational<I> other_negato = Rational<I>(-other.num(), other.den());
            *this += other_negato;
            return *this;
        }

        Rational<I> operator-(const Rational<I>& other) {
            Rational diff = *this;
            diff -= other;
            return diff;
        }

        Rational<I> operator*=(const Rational<I>& other) {
            // NaN moltiplicato a qualsiasi cosa da NaN
            if((den_==0 && num_==0) || (other.den()==0 && other.num()==0)){
                this->set_nan();
            }

            // Inf * 0 (o 0 * Inf) è una forma indeterminata, quindi restituisco NaN
            else if((den_==0 && other.num()==0 && other.den()!=0) ||
                    (other.den()==0 && num_==0 && den_!=0)){
                this->set_nan();
            }

            // Se almeno uno dei due è infinito e non ho NaN né 0 restituisco Inf considerando i segni
            else if(den_==0 || other.den()==0){
                if(num_ * other.num() < 0) this->set_inf(false);
                else this->set_inf(true);
            }

            else{
                this->num_ = num_ * other.num();
                this->den_ = den_ * other.den();
            }
            return *this;
        } //Non semplifico perchè lo farò una volta stampato

        Rational<I> operator*(const Rational<I>& other) {
            Rational prod = *this;
            prod *= other;
            return prod;
        }

        Rational<I> operator/=(const Rational<I>& other) {
            //se ho un NaN il risultato è NaN
            if((den_==0 && num_==0) || (other.den()==0 && other.num()==0)){
                this->set_nan();
                return *this;
            }

            //qualunque combinazione di Inf / Inf è indeterminata
            if((num_!=0 && den_==0) && (other.num()!=0 && other.den()==0)){
                this->set_nan();
                return *this;
            }

            //0/0 è NaN
            if(num_==0 && other.num()==0){
                this->set_nan();
                return *this;
            }
            
            //Caso generale: a/b = a * (1/b)
            I inv_num = (other.num() < 0) ? -other.den() :  other.den();
            I inv_den = (other.num() < 0) ? -other.num() :  other.num();
            Rational<I> other_inverso = Rational<I>(inv_num, inv_den);

            *this *= other_inverso;
            return *this;
        } //Non semplifico perchè lo farò una volta stampato

        Rational<I> operator/(const Rational<I>& other) {
            Rational div = *this;
            div /= other;
            return div;
        }
};
