
## Suunnittelua

Tavoitteena on rakentaa laite jonka voi sijoittaa kotona omien avaimien läheisyyteen. Laite toimii siten että jos kodin ovi avautuu, mutta henkilön avaimet ovat vielä laitteen läheisyydessä, laite päästää hälytysäänen. Tällä varmistetaan se että henkilö ei lähde kotoaan ilman avaimiaan. 

Laitteeseen tarvitaan itse tietokone, ja tässä vaiheessa tietokoneeksi valikoitui Arduino UNO R4 WiFi. Aluski suunnitelmissa käytettiin Rasberry PI:tä, sillä siitä projektin tekijöillä oli hieman kokemusta. Mutta myöhemmin päätettiin vaihtaa Arduinoon, sillä kurssin opettajien mielestä tämä oli parempi vaihtoehto. Lisäksi tarvitaan RFID tunnistin sekä tageja (avaimenperiä) jotka ovat kiinni avaimissa. RFID lukijoita hankittiin kaksi kappaletta, mahdollisen rikkoutumisen vuoksi. Ja myös oveen tarvitaan jonkinlainen magneettikytkin joka seuraa onko ovi auki vai kiinni. Lisäksi tarvitaan myös koodia yhdistämään kaikki laitteen osat. Koodi on hieman muunneltua C++ koodia. 

Lista ostetuista materiaaleista löytyy [materiaalit.md](https://github.com/kreatiini/DLYKH/blob/main/materiaalit.md) sisältä. 



## Tiedonhaku

Tiedonhaussa perehdyttiin yleisesti Arduinon toimintaan. Mikä se on? Miten se toimii? Mitä sovelluksia sen käyttöön tarvitaan? Suurin osa koodista etsitään internetistä, jonka jälkeen se yritetään sovittaa projektiin. Jokaisella osallistujalla on hieman kokemusta ohjelmoinnista, mutta ei tarpeeksi että koodin saisi kokonaan itse kirjoitettua.


## Laitteiden hankinta

Kaikki laitteet ostettiin  Partco elektroniikkaliikkeestä vantaalta. [Linkki Partcon sivuille.](https://www.partco.fi/fi/)


## Välineiden alkutestaus
Alkutestauksen aikana Arduino UNO R4 WiFI otettiin käyttöön ja saatiin toimimaan. Ensimmäinen käyttööotto tapahtui [Arduino Documentationin](https://docs.arduino.cc/hardware/uno-r4-wifi/?_gl=1*18rlor6*_up*MQ..*_ga*NDgzNjE1MDEzLjE3NDQ2MTY5MTY.*_ga_NEXN8H46L5*MTc0NDYxNjkxNC4xLjEuMTc0NDYxNjkyMC4wLjAuODQ0MzMyNDQ0) avulla. Testauksen aikana RFID lukija saatiin toimimaan, siten että lukija tunnisti RFID tagin läheisyyden, ja sen poistamisen. Suunnitelmasssa laite toimisi siten että kun RFID tagi on laitteen läheisyydessä, ja ja jos magneettikytkin avataan, kuuluu hälytysääni. Kaiutinta ei ole vielä yhdistetty mutta laite tunnistaa RFID tagin ja ilmoittaa siitä Arduino IDE sovelluksen kautta Debuggerissa. 

## Laitteiden yhdistelemistä

![kuva1](https://github.com/user-attachments/assets/8693061f-cf86-4335-a8bd-adc87c64afd0)
*projektin työstämistä koululla*

Laitteiden alkutestauksen aikana RFID laite toimi normaalisti. Mutta seuraavalla tapaamiskerralla törmättiin ensimmäisiin ongelmiin. Toistettaessa edellisen työkerran osia, kaikki toiminutkaan.

![error message](https://github.com/user-attachments/assets/32a73202-c83e-483d-8a07-172856e0f897)

Jostain syystä Arduino debugger ei toiminut. Itse koodi toimii RFID lukijan kanssa sillä Arduino laudassa oleva pieni ledi antaa merkin siitä että RFID tagi on tunnistettu. Joten itse debuggerissa on jokin vika. Debuggerin vika korjautui lopulta kun asensi IDE sovelluksen udestaan, mutta koodin kanssa tuli lisää ongelmia. Lopulta piuhojen tarkastus ja uudelleenasettaminen sai vian korjattua. 

![tag found](https://github.com/user-attachments/assets/b7af5ab7-696f-4b97-9b00-56796ab406c1)

NFC-Tagin löytyminen saatiin toimimaan kuten kuvasta näkyy. Seuraavaksi vuorossa on magneettikytkimen kiinnittäminen ja kaijuttimen yhdistäminen siten, että kaijutin hälyttää jos tagi otetaan pois.

## Magneettikytkimen ja kaiuttimen yhdistäminen

Magneettikytkimen ja kaiuttimen yhdistämiseen löytyi paljon tietoa verkosta. Alkuun testattiin ensin pelkkä kaiutin hyvin lyhyellä koodinpätkällä. (https://wiki.seeedstudio.com/Grove-Buzzer/). Kaiutin toimi hyvin. Tämän jälkeen piti lisätä magneettikytkin ja testata sen toimintaa. Magneettikytkimen ja kaiuttimen yhdistämiseen löytyi suoraan ohjeet netistä: https://www.instructables.com/How-to-Use-a-Magnetic-Door-Switch-Sensor-With-Ardu/. Esimerkistä kuitenkin poiketen kytkin oli "LOW" ollessa kiinni ja "HIGH" auki. Ne piti siis kääntää ympäri. Tämän muutoksen jälkeen molemmat lähtivät toimimaan. 

## Magneettikytkin, lukija ja kaiutin kasaan

Tämä vaihe oli omalla tavallaan haasteellinen heikosta ohjelmointitaustasta johtuen. Koodi kuitenkin löytyi lukijaan, magneettikytkimeen sekä kaiuttimeen jo valmiiksi. Tämä vaihe vaati hieman perehtymistä C++/Arduinossa käytettäviin funktioihin. Ajatuksena siis tehdä jokaisesta laitteesta funktio ja ehtojen täyttyessä kaiutin päästää äänen. Tämä oli yllättävän haasteellista. Kesti aika kauan aikaa ensin muodostaa jollain tavalla ymmärrettävän näköinen kokonaisuus. Tämän jälkeen meni hetki saada kokonaisuus toimimaan oikein. Se kuitenkin onnistui. Ja näin pääidea saatiin kasaan, laite toimimaan vähimmäistasolla.

## Napin lisääminen

Viimeisenä oli tarkoitus lisätä nappi, jolla hälytys saadaan pois päältä kahdeksi minuutiksi. Ensimmäinen nappi hajosi repussa. Onneksi Plug & Make kitin mukana tuli kolmen napin palikka jota pystyimme hyödyntämään. Tämä palikka hyödynsi Arduinon Qwiick liitintä. Sitä ei siis tarvinnut yhdistää erillisiin kohtiin Arduinossa. Tämän jälkeen piti etsiä Modulino moduuli ja asentaa se. Suunnitelma oli sama eli tehdä napille funktio ja ehtojen täyttyessä se hiljentää kaiuttimen kahdeksi minuutiksi. Käytin napin koodin apuna tätä https://forum.digikey.com/t/arduino-modulino-buttons-tutorial/44899 ohjetta joka oli hyvä ja selventävä. Perehtyessäni Modulino osien toimintaan katselin niitä myös täältä https://projecthub.arduino.cc/metehocax/arduino-plug-and-make-kit-all-modulino-demo-99ad53 . 

## Valmis laite, perusperiaate.

![Laitteen osat valmiissa laitteessa](https://github.com/user-attachments/assets/167d205a-7dea-423f-95f7-428323fa3ab2)

A: Avain, sekä avamen paikka. Jos paikka on tyhjä ja ovikytkin aukeaa, ei ääntä kuulu. 

B: Ovikytkin. Jos avain on paikallaan ja ovikytkin aukeaa, kuuluu hälytysääni.

C: Laitteen kaijutin josta tulee äänimerkki.

D: Arduino UNO R4 WiFi, laitteen aivot.

## Valmis laite, hiljennysnapin kanssa.

![Valmis + nappi](https://github.com/user-attachments/assets/0a636f91-520c-4e76-922a-4a6d8f191c16)

E: Laitteen hiljennysnappi. Nappia painaessa laite hiljenee kahdeksi minuutiksi. Eli oven voi avata siten että avain on paikallaan, eikä laite hälytä.


Projektin lyhyt [demovideo](https://youtu.be/VMIWuo55bsI)
Projektin toinen tarinallinen [demovideo](https://youtu.be/eoO5MgIFSag)

# Lähteitä

- How to Use a Magnetic Door Switch / Sensor With Arduino, Autodesk Instructables, [Linkki](https://www.instructables.com/How-to-Use-a-Magnetic-Door-Switch-Sensor-With-Ardu/)
- Arduino Docs, UNO R4 WiFi, [Linkki](https://docs.arduino.cc/hardware/uno-r4-wifi/?_gl=1*18rlor6*_up*MQ..*_ga*NDgzNjE1MDEzLjE3NDQ2MTY5MTY.*_ga_NEXN8H46L5*MTc0NDYxNjkxNC4xLjEuMTc0NDYxNjkyMC4wLjAuODQ0MzMyNDQ0)
- Arduino, Software download Arduino IDE, [Linkki](https://www.arduino.cc/en/software/)
- Markdown Guide, Markdown Cheat Sheet, [Linkki](https://www.markdownguide.org/cheat-sheet/)
