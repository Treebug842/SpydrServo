# SpydrServo
Arduino library for using continous servo motors as normal servo motors using a potentiometer. This project is basically because I accidently bought a bunch of continous rotation servo motors instead of normal 180 degree servo motors. So I made this library, that allows to servo (paired with a potentiometer) to be writable to a certain angle (with + or - 4 degree margine for error). Its designed to work with the potentiometer and servo being attached together, so the poteniometer rotates as the servo does, there is example code for how to use is; but the basic terms are;
``` 
SpydrServo object;
object.attach(servoPin, potPin);
object.detach();
object.write(pos);
object.read();
```

