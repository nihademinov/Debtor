#include <string>
#include <iostream>
#include <list>
#include<algorithm>
using namespace std;

class Debtor {
    string _FullName;
    string _Phone;
    string _Email;
    string _Address;
    // Private Birthday Information
    int _year;
    short _month;
    short _day;
    // Debt
    int _Debt;
public:
    Debtor(string name, int year, short month, short day, string phone, string email, string adress, int debt)
    {
        setName(name);
        setPhone(phone);
        setemail(email);
        setYear(year);
        setMonth(month);
        setDay(day);
        setDebt(debt);
    }
    
    void setName(string name)
    {
        if (name == " ")
        {
            try
            {
                throw exception("Name can not be empty");
            }
            catch (const std::exception& ex)
            {
                cout << ex.what() << endl;
            }
        }
        else
        {
            this->_FullName = name;
        }
    }

    void setPhone(string phone)
    {
        bool check = true;
        for (size_t i = 0; i < phone.length(); i++)
        {
            if (!(isdigit(phone[i])))
            {
                check = false;
            }
        }
        if (check)
        {
            this->_Phone = phone;
        }
        else
        {
            try
            {
                throw exception("Number can not be empty");
            }
            catch (const std::exception& ex)
            {
                cout << ex.what() << endl;
            }
        }
    }

    void setemail(string email)
    {
        bool check = false;
        for (size_t i = 0; i < email.length(); i++)
        {
            if (email[i] == '@') 
            {
                check = true;
            }
        }
        if (check)
        {
            this->_Email = email;
        }
        else
        {
            try
            {
                throw exception("Email must consist of @");
            }
            catch (const std::exception& ex)
            {
                cout << ex.what() << endl;
            }
        }
    }

    void setYear(int year)
    {
        if (year > 1900 || year < 2022)
        {
            this->_year = year;
        }
        else
        {
            try
            {
                throw exception("Year undifine");
            }
            catch (const std::exception& ex)
            {
                cout << ex.what() << endl;
            }
        }
    }

    void setMonth(short month)
    {
        if (month > 0 && month < 13)
        {
            this->_month = month;
        }
        else
        {
            try
            {
                throw exception("Wrong month");
            }
            catch (const std::exception& ex)
            {
                cout << ex.what() << endl;
            }

        }
    }

    void setDay(short day)
    {
        if (day > 0 && day < 32)
        {
            this->_day = day;
        }
        else
        {
            try
            {
                throw exception("wrog day");
            }
            catch (const std::exception& ex)
            {
                cout << ex.what() << endl;
            }
        }
    }

    void setDebt(int debt)
    {
        if (debt > 0)
        {
            this->_Debt = debt;
        }
        else
        {
            try
            {
                throw exception("Debt can not be negative");
            }
            catch (const std::exception& ex)
            {
                cout << ex.what() << endl;
            }
        }
    }



    friend ostream& operator<<(ostream& print, const Debtor& other)
    {
        print << "Info" << endl;
        print << "Name: " << other._FullName << endl;
        print << "Birthday: " << other._day << "." << other._month << "." << other._year << endl;
        print << "Phone: " << other._Phone << endl;
        print << "Email: " << other._Email << endl;
        print << "Address: " << other._Address << endl;
        print << "Debt: " << other._Debt << endl;
        return print;
    }

    string getName() { return this->_FullName; }

    string getPhone() { return this->_Phone; }

    string getEmail() { return this->_Email; }

    int getYear() { return this->_year; }

    short getMonth() { return this->_month; }

    short getDay() { return this->_day; }

    int getDebt() { return this->_Debt; }

};


bool checkDomein(Debtor * deb)
{
    bool check = false;
    string tempDomein;
    for (size_t i = 0; i <deb->getEmail().length(); i++)
    {
        if (deb->getEmail()[i] == '@')
        {
            check = true;
            continue;
        }

        if (check)
        {
            tempDomein += deb->getEmail()[i];
        }
    }
    if (tempDomein == "rhyta.com" || tempDomein == "dayrep.com")
    {
        cout << *deb;
        return true;
    }
    return false;
    
}

bool FindAge(Debtor* deb)
{
    int debAge = 2023 - deb->getYear();
    if (debAge >= 26 && debAge <= 36)
    {
        cout << *deb;
        return true;
    }
    return false;
}

bool find5000Debt(Debtor* deb)
{
    if (deb->getDebt() <= 5000)
    {
        cout << *deb;
        return true;
    }
    return false;
}


bool CrazyDebtor(Debtor* deb)
{
    bool checkName = false;
    bool checkPhone = false;
    int count = 0;

    if (deb->getName().length() > 18)
    {
        checkName = true;
    }

    for (size_t i = 0; i < deb->getPhone().length(); i++)
    {
        if (deb->getPhone()[i] == '7')
        {
            count++;
        }
    }
    if (count >= 2)
    {
        checkPhone = true;
    }

    if (checkName && checkPhone)
    {
        cout << *deb;
        return true;
    }
    return false;
}

bool checkWinterDebtor(Debtor* deb)
{
    if (deb->getMonth() == 12 || deb->getMonth() == 1 || deb->getMonth() == 2)
    {
        cout << *deb;
        return true;
    }
    return false;
}



bool AvarageDebtGreaterDebtor(Debtor* deb1,Debtor*deb2)
{
    if (deb1->getDebt() > deb2->getDebt())
    {
        cout << *deb1;
        return true;
    }
    return false;
}

bool without8inPhone(Debtor* deb)
{
    bool checkNumber = true;
    for (size_t i = 0; i < deb->getPhone().length(); i++)
    {
        if (deb->getPhone()[i] == '8')
        {
            checkNumber = false;
        }
    }
    if (checkNumber)
    {
        cout << *deb;
        return true;
    }
    return false;
}


bool sameAlphabetName(Debtor* deb)
{
    int count = 0;
    for (int i = 0; i < deb->getName().length(); i++)
    {
        for (size_t j = i+1; j < deb->getName().length(); j++)
        {
            if (deb->getName()[i] == deb->getName()[j] && i != j)
            {
                count++;
            }
        }
    }

    if (count >= 3)
    {
        cout << *deb;
        return true;
    }
    return false;
}

bool maxYear(Debtor* deb1,Debtor *deb2)
{
    return deb1->getYear() > deb2->getYear();
}


void main()
{

    list<Debtor*> debtors = 
    {
            new Debtor("Shirley T. Qualls", 2011, 7, 8, "0506882423", "ShirleyTQualls@teleworm.us", "3565 Eagles Nest Drive Woodland, CA 95695", 2414),
            new Debtor("Danielle W. Grier", 1999, 3, 8, "0506882423",  "DanielleWGrier@rhyta.com", "1973 Stoneybrook Road Maitland, FL 32751", 3599),
            new Debtor("Connie W. Lemire", 2000, 1, 8, "0506882423",  "ConnieWLemire@rhyta.com", "2432 Hannah Street Andrews, NC 28901", 1219),
            new Debtor("Coy K. Adams", 2000, 12, 3, "0506882423",  "CoyKAdams@dayrep.com", "2411 Blue Spruce Lane Baltimore, MD 21202", 3784),
            new Debtor("Bernice J. Miles", 2000, 5, 8, "0506552423",  "BerniceJMiles@armyspy.com", "4971 Austin Avenue Savannah, GA 31401", 4060),
            new Debtor("Bob L. Zambrano", 1834, 8, 8, "0506882423", "BobLZambrano@armyspy.com", "2031 Limer Street Augusta, GA 30901", 6628),
            new Debtor("Adam D. Bartlett",1999, 6, 8, "0506882423", "AdamDBartlett@rhyta.com", "2737 Rardin Drive San Jose, CA 95110", 5412),
            new Debtor("Pablo M. Skinner", 2000, 8, 8, "0506882423", "PabloMSkinner@armyspy.com", "16 Fraggle Drive Hickory Hills, IL 60457", 11097),
            new Debtor("Dorothy J. Brown", 1920, 9, 8, "0506882423", "DorothyJBrown@rhyta.com", "699 Harper Street Louisville, KY 40202", 7956),
            new Debtor("Larry A. Miracle", 1834, 10, 8, "0506882423", "LarryAMiracle@jourrapide.com", "2940 Adams Avenue Columbia, MD 21044", 7150),
            new Debtor("Donna B. Maynard", 1987, 10, 8, "0506882423", "DonnaBMaynard@teleworm.us", "4821 Elk Rd Little Tucson, AZ 85704", 2910),
            new Debtor("Jessica J. Stoops",2011, 11, 8, "0506882423", "JessicaJStoops@dayrep.com", "2527 Terra Street Custer, WA 98240", 11805),
            new Debtor("Audry M. Styles", 1999, 1, 8, "0506882423", "AudryMStyles@jourrapide.com", "151 Christie Way Marlboro, MA 01752", 1001),
            new Debtor("Violet R. Anguiano",1834, 2, 8, "0506882423", "VioletRAnguiano@dayrep.com", "1460 Walt Nuzum Farm Road Rochester, NY 14620", 9128),
            new Debtor("Charles P. Segundo", 2000, 1, 8, "0506882423", "CharlesPSegundo@dayrep.com", "1824 Roosevelt Street Fremont, CA 94539", 5648),
            new Debtor("Paul H. Sturtz",2001, 12, 3, "0506882423", "PaulHSturtz@dayrep.com", "759 Havanna Street Saxapahaw, NC 27340", 10437),
            new Debtor("Doris B. King",2000, 12, 3, "0506882423", "DorisBKing@rhyta.com", "3172 Bedford Street Birmingham, AL 35203", 7230),
            new Debtor("Deanna J. Donofrio", 1834, 3, 8, "0506882423", "DeannaJDonofrio@rhyta.com", "1972 Orchard Street Bloomington, MN 55437", 515),
            new Debtor("Martin S. Malinowski", 2000, 5, 8, "0506882423", "MartinSMalinowski@dayrep.com", "3749 Capitol Avenue New Castle, IN 47362", 1816),
            new Debtor("Melissa R. Arner", 2000, 7, 6, "0506882423", "MelissaRArner@armyspy.com", "922 Hill Croft Farm Road Sacramento, CA 95814", 5037),
            new Debtor("Kelly G. Hoffman", 1920, 12, 8, "0506882423", "KellyGHoffman@armyspy.com", "4738 Chapmans Lane Grants, NM 87020", 7755),
            new Debtor("Doyle B. Short", 2001, 12, 8, "0506882423", "DoyleBShort@teleworm.us", "124 Wood Street Saginaw, MI 48607", 11657),
            new Debtor("Lorrie R. Gilmore", 2000, 12, 8, "0506882423", "LorrieRGilmore@teleworm.us", "74 Pine Street Pittsburgh, PA 15222", 9693),
            new Debtor("Lionel A. Cook", 1834, 8, 8, "0506882423", "LionelACook@jourrapide.com", "29 Goldleaf Lane Red Bank, NJ 07701", 2712),
            new Debtor("Charlene C. Burke", 2001, 12, 8, "0506882423", "CharleneCBurke@armyspy.com", "4686 Renwick Drive Philadelphia, PA 19108", 4016),
            new Debtor("Tommy M. Patton",2000, 12, 8, "0506882423", "TommyMPatton@rhyta.com", "748 Rockford Road Westborough, MA 01581", 349),
            new Debtor("Kristin S. Bloomer",1920, 12, 8, "0506882423", "KristinSBloomer@dayrep.com", "15 Hewes Avenue Towson, MD 21204", 9824),
            new Debtor("Daniel K. James", 1834, 8, 8, "0506882423", "DanielKJames@rhyta.com", "3052 Walton Street Salt Lake City, UT 84104", 8215),
            new Debtor("Paula D. Henry", 2000, 12, 8, "0506882423", "PaulaDHenry@rhyta.com", "3575 Eagle Street Norris City, IL 62869", 5766),
            new Debtor("Donna C. Sandoval",1999, 12, 8, "0506882423", "DonnaCSandoval@rhyta.com", "675 Jehovah Drive Martinsville, VA 24112", 8363),
            new Debtor("Robert T. Taylor",2000, 8, 8, "0506882423", "RobertTTaylor@armyspy.com", "2812 Rowes Lane Paducah, KY 42001", 7785),
            new Debtor("Donna W. Alamo", 1920, 12, 8, "0506882423", "DonnaWAlamo@teleworm.us", "4367 Christie Way Marlboro, MA 01752", 10030),
            new Debtor("Amy R. Parmer", 2001, 7, 8, "0506882423", "AmyRParmer@armyspy.com", "85 Elmwood Avenue Chandler, AZ 85249", 5347),
            new Debtor("Newton K. Evans", 2000, 12, 8, "0506882423", "NewtonKEvans@rhyta.com", "3552 Columbia Road Greenwood Village, CO 80111", 9838),
            new Debtor("Kathleen C. Chaney", 1920, 12, 8, "0506882423", "KathleenCChaney@rhyta.com", "316 Elsie Drive Fort Thompson, SD 57339", 1672),
            new Debtor("Manuel C. Johnson", 2000, 12, 8, "0506882423", "ManuelCJohnson@jourrapide.com", "4146 May Street Sharpsburg, KY 40374", 9195),
            new Debtor("Carla A. Creagh", 1920, 12, 8, "0506882423", "CarlaACreagh@dayrep.com", "3106 Bates Brothers Road Columbus, OH 43215", 11271),
            new Debtor("Norma M. New", 2000, 12, 8, "0506882423", "NormaMNew@jourrapide.com", "965 Metz Lane Woburn, MA 01801", 9761),
            new Debtor("Roy D. Green",2000, 1, 8, "0506882423", "RoyDGreen@jourrapide.com", "401 Romrog Way Grand Island, NE 68801", 10771),
            new Debtor("Cristy J. Jensen", 1920, 2, 8, "0506882423", "CristyJJensen@jourrapide.com", "2177 Harley Vincent Drive Cleveland, OH 44113", 5205),
            new Debtor("Nancy J. Fergerson", 2001, 10, 8, "0506882423", "NancyJFergerson@dayrep.com", "3584 Jadewood Drive Demotte, IN 46310", 1276),
            new Debtor("Dave N. Rodriguez", 1989, 12, 8, "0506882423", "DaveNRodriguez@rhyta.com", "1890 Poco Mas Drive Dallas, TX 75247", 9132),
            new Debtor("James E. Denning", 1920, 3, 8, "0506882423", "JamesEDenning@jourrapide.com", "1444 Rose Avenue Metairie, LA 70001", 8176),
            new Debtor("Richard M. Thomas", 1990, 4, 8, "0506882423", "RichardMThomas@jourrapide.com", "4454 Green Avenue Oakland, CA 94609", 7875),
            new Debtor("Lakisha R. Forrest",2001, 5, 8, "0506882423", "LakishaRForrest@armyspy.com", "3121 Quarry Drive Montgomery, AL 36117", 3088),
            new Debtor("Pamela H. Beauchamp", 1999, 6, 8, "0506882423", "PamelaHBeauchamp@jourrapide.com", "3239 Tori Lane Salt Lake City, UT 84104", 6588)
    };


 
    //1)rhyta.com ve ya dayrep.com domenlerinde emaili olan borclulari cixartmag
    // 
    //for_each(begin(debtors), end(debtors), checkDomein);
    
    //--------------------------------------------------------------------
    //2)Yashi 26 - dan 36 - ya qeder olan borclulari cixartmag
    // 
    //for_each(begin(debtors), end(debtors), FindAge);
  
    //------------------------------------------------------------------------
    // 3)Borcu 5000-den cox olmayan borclularic cixartmag
    // 
    //for_each(begin(debtors), end(debtors), find5000Debt);
    
    //--------------------------------------------------------------------------
    //4)Butov adi 18 simvoldan cox olan ve telefon nomresinde 2 ve ya 2-den cox 7 reqemi olan borclulari cixartmaq

    //for_each(begin(debtors), end(debtors), CrazyDebtor);

    //---------------------------------------------------------------------------
    //5) Qishda anadan olan borclulari cixardmaq

    //for_each(begin(debtors), end(debtors), checkWinterDebtor);

    //---------------------------------------------------------------------------
    //6)Borcu, umumi borclarin orta borcunnan cox olan borclulari cixarmaq

    //auto find = max_element(begin(debtors), end(debtors), AvarageDebtGreaterDebtor);

    //-------------------------------------------------------------------------------------
    //7) Telefon nomresinde 8 olmayan borclularin yalniz familyasin,yashin ve umumi borcun meblegin cixarmaq

    //for_each(begin(debtors), end(debtors), without8inPhone);

    //---------------------------------------------------------------------------------------
    //8)Adinda ve familyasinda hec olmasa 3 eyni herf olan borclularin siyahisin cixarmaq ve onlari elifba sirasina gore sortirovka elemek

    //for_each(begin(debtors), end(debtors), sameAlphabetName);

    //-------------------------------------------------------------------------------------------
    //9)borclulardan en coxu hansi ilde dogulubsa hemin ili cixartmaq

    //auto find = max_element(begin(debtors), end(debtors), maxYear);

    
    

}


