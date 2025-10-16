# inl-mning1_julio
min inlämningsuppgift i programmering c++
Det här programmet låter användaren arbeta med 5 tal.
Man kan mata in talen, visa statistik, söka efter ett tal, sortera talen och avsluta programmet.
Allt styrs via en meny som gör programmet enkelt att använda.

Programmet kan:

Lägga till 5 nya värden

Visa statistik:

Summa

Medelvärde

Högsta tal

Lägsta tal

Varians (stickprov)

Standardavvikelse (stickprov)

Söka efter ett värde

Sortera värdena i stigande ordning

Avsluta programmet

*********Hur programmet fungerar*******

Programmet visar en meny med fem alternativ.

Användaren väljer ett alternativ genom att skriva en siffra.

Varje menyval kör en egen funktion.

Användaren kan göra flera saker innan programmet avslutas.

Programmet hanterar även ogiltig inmatning (t.ex. om man skriver bokstäver istället för siffror) så att programmet inte kraschar.

*********Funktioner i programmet*******

Programmet använder flera funktioner för att göra koden tydligare:

showMenu() – visar menyn

sum() – räknar ihop alla tal

average() – räknar medelvärde

highest() – hittar största talet

lowest() – hittar minsta talet

findIndex() – letar efter ett värde i arrayen

varianceSample() – räknar varians

standardDeviationSample() – räknar standardavvikelse

sortAscending() – sorterar talen i stigande ordning (bubble sort)

Alla funktioner är skrivna på ett enkelt och tydligt sätt med måsvingar och utan förkortningar (t.ex. += och ++) för att göra koden lättare att förstå för en nybörjare.

*******Felhantering*******

Om användaren skriver något som inte är ett tal används följande kod: 
cin.clear(); tar bort felstatusen så att cin går att använda igen.
cin.ignore(numeric_limits<streamsize>::max(), '\n');   tar bort felaktig input från bufferten så att den inte stör nästa inmatning. Jag lärde mig detta av AI, och det hjälpte mig förstå hur man hanterar ogiltig input på ett säkert sätt.

***********Svårigheter jag hade under arbetet**********

När jag började med uppgiften hade jag flera problem:

Jag använde inte måsvingar {}, vilket gjorde koden svår att läsa

Jag lade break inne i en for-loop av misstag

Jag använde while(choice != 5) men choice hade inget startvärde

Min bubble sort jämförde fel index (i istället för j)

Jag visste inte hur man hittar max/min på rätt sätt

Jag visste inte hur man hanterar felaktig input

Jag använde förkortningar (t.ex. += och ++) som gjorde koden mer svår för mig själv

***********Vad jag har lärt mig***********

Under arbetet lärde jag mig:

Hur man skriver ett menybaserat program

Hur man delar upp koden i funktioner

Hur man skickar en array till en funktion (med size)

Hur bubble sort fungerar

Hur man hanterar ogiltig input korrekt

Varför tydlig kod med måsvingar är viktigt

Hur man skriver kod som är lätt att läsa
