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
