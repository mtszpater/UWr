//
// Created by Mateusz Pater on 25.03.2016.
//

#include "list.h"


    list::wezel::wezel(){
        val = string();
    }

    list::wezel::wezel(const string &_val){
        val = _val;
    }

    list::wezel* list::wezel::return_next(){
        if(next != 0) {
            return next;
        }

        return 0;

    }

    list::wezel::~wezel(){
        delete next;
    }

    void list::wezel::set_next( wezel* _n ){
        next = _n;
    }

    const string& list::wezel::return_val (){
        return val;
    }

    void list::wezel::set_val ( const string &_val ){
        val = _val;
    }

    list::list()
    {
        first = new wezel();
    }

    list::list(const string &_val)
    {
        first = new wezel(_val);
    }


    list::list(const list &rhs) :
            first(rhs.first)
    {
        *this = rhs;
    }

    list::list(list &&rhs)
    {
    *this = std::move(rhs);
    }

    list & list::operator=(const list &rhs)
    {
        if (this != &rhs)
        {
            if (first != rhs.first)
            {
                delete[] first;
                first = new wezel();
                first = rhs.first;
            }
        }
        return *this;
    }

    list & list::operator=(list &&rhs)
    {
        first  = std::move(rhs.first);
        rhs.first = 0;
        return *this;
    }




    void list::insert( const string &_val, int poz){


        if(first->return_val() == string()){
            first->set_val(_val);
            return;
        }

        wezel *tmp = new wezel(_val);

        if(poz < 0)
        {
            throw std::invalid_argument("Invalid argument");
        }

        if(poz == 0)
        {
            tmp->set_next(first);
            first = tmp;

            return;
        }



        int thisPosition = 1;
        wezel *f = first;

        while( f->return_next() != 0 && thisPosition != poz){

            f = f->return_next();
            ++thisPosition;

        }

        if( poz >= thisPosition ){
            tmp->set_next(f->return_next());
        }

        f->set_next(tmp);




    }


    const string& list::read( int poz ){

        if(poz < 0)
        {
            throw std::invalid_argument("Invalid argument");
        }

        if( poz == 0) return first->return_val();

        wezel *f = first;

        int thisPosition = 0;

        while( f->return_next() != 0 && thisPosition != poz){

            f = f->return_next();
            ++thisPosition;
        }

        if( poz > thisPosition ){
            throw std::invalid_argument("Invalid argument");
        }

        return f->return_val();

    }


    void list::remove( int poz ){

        if( !first ) return;

        if(poz < 0)
        {
            throw std::invalid_argument("Invalid argument");
        }
        if( poz == 0) {
            first = first->return_next();
            return;
        }

        wezel *f = first;

        int thisPosition = 1;


        while( f->return_next() != 0 && thisPosition != poz){

            f = f->return_next();
            ++thisPosition;
        }

        if( poz > thisPosition ){
            throw std::invalid_argument("Invalid argument");
        }

        wezel *tmp = f->return_next();
        f->set_next(tmp->return_next());



    }

    list::list( initializer_list<string> lst) {
        first = new wezel();
        for(string _lst : lst) {
            insert(_lst, (int) lst.size());
        }
    }


    int list::size(){

        wezel *tmp = first;

        int size = 0;

        while( tmp != 0 ){
            tmp = tmp->return_next();
            ++ size;

        }

        return size;
    }

    ostream& operator << (ostream &wy, const list &lst) {
        if(lst.first) return wy << "(" << *lst.first << ")"; else return wy << "()";
    }


    ostream& operator << (ostream &wy, const list::wezel &wzl){
        if (wzl.next) return wy << wzl.val << ", " << *wzl.next; else return wy << wzl.val;
    }


    list::~list(){

    }
