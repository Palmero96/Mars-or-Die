# Mars-or-Die
C++ and OpenGL based videogame in building process

This is a University project made by Ignacio Rodríguez Naranjo and Elena Rodríguez Álvarez, tutored by Dr. Miguel Hernando.
We are both Industrial Electronics and Automatics Engineering students in the Technical University of Madrid (UPM - ETSIDI)

The point of the project is to develope basic skills in C++ and industrial communications, as well as to get a better 
understanding of data management in computers and microprocessors.

It consists of a 3D graphics game in which the point is to get a cargo and human spaceship to... MARS!!

There are several phases on the game:
  The first one consists on selecting the appropiate time to launch the spaceship according to the orbital position of
Mars and the Earth. Once you get that right, the spaceships first stage needs to get unlocked from the rest of the shuttle.

  The next move is to get the space shuttle save from the Earth to Mars, an adventure in which you'll have to avoid 
dangerous asteroids, friendly aliens who want you to sign and donate money for the "Save the spontaneous appearing Whales" 
organization and get "Towel Bonus" and extra fuel in order to continue the trip.

  If you have the skills to get here, human race we'll be saved, but first!... You'll need to land the spaceship in Mars!!
Good luck stabilizing the Dragon Capsule with its engines! 
  
  May the force be with you and Don't Panic!
  
******************************************************************************************************************
  
UPDATES AND COMMENTS

May 13th 2017:
   - Code has been cleaned and reorganiced.
   - So far the Earth and Mars orbit the sun in circular orbits.
   - The orbits are drawn in the screen using GL_LINE_LOOP and 
        drawing multiple lines of these kind in a for loop.
        
May 14th 2017
   - Added Venus.
   - Implemented the 'Shot' class, which point is to reflect the trayectory 
        that our shuttle must go through. Eventually it will be drawn just 
        when you press a certain key, Alt+Ctrl+Shift+N+F11, for instance.
        
May 17th 2017
   - 'Shot' Class deleted. Reason on update's description. You can go find it yourself, can't you?
   - Reorganiced code. The planets apparentely orbit the same way they use
        to did, but the whole internal structure has been changed. 
        Now everything should be kinda cleaner. The dependence now is the linear velocity,
        instead of the angular.
    - Introduced a 'Ship' Class that will represent, guess what... THE SHIP! CORRECT!
        Its dinamicaly created. Its movement depends on:
         1- Earth's velocity and position at the moment of the launch.
         2- Sun's gravital force, that diminishes with the distance to it's surface (cool, uh?).
         3- Velocity given by its engines (thrust).

June 8th 2017
   - Created the basic class 'Object'.
   - Created the basic class 'Moving Object', that inherits physical properties from Object.
   - Sphere, Planet and Ship rely now on these basic classes, making each of them 
        responsible for their own information.
   - The ship still makes weird stuff wheen it's launched.
   
June 11th 2017
   - Created the class 'Interaction' that will handle the interaction between the ship and 
        Mars, if they get close enough.
   - The ship is launched with a radial trayectory by pressing the space bar:
       -Once it's pressed, the ship is launched and the planets slow down, as a way to 
        approximate how the ships and planets velocity (It's completely and absolutely 
        inaccurate, but it looks awesome)
       -If you press again the planets get back their velocity and you can shoot again.
       
June 13th 2017
   - The ship finally moves properly. Now, once the ship and Mars are close enough, our 
    shuttle begins an orbital movement around Mars and so, this phase is FINISHED!
    
June 18th 2017
   - There's a pretty awesome start menu
   - The structure of the code has been changed: Now the class World, which manages the first 
        phase of the game, is managed by the class Coordinator, which will handle all the 
        different phases and when to switch from one to the next one.
   - Also there's music ( Star Wars score of course)
   
June 20th 2017
   - There is a Pause phase available pressing 'p' at any given moment
   - Textures applyed to planets and sun
   - More code stuff
