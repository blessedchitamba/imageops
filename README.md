# imageops
CS3022H Assignment 4: Image processing application. Operator overloading etc.
Uses C++ templating and operator overloading techniques to manipulate grayscale images using various filters etc.
Run 
      ./imageops -i Lenna_standard.pgm addTest_2.pgm
for an example operation. Options are:
 The options are of the form (I1 and I2 represent image filenames):
-a I1 I2 (add I1 and I2)
-s I1 I2 (subtract I2 from I1)
-i I1 (invert I1)
-l I1 I2 (mask I1 with I2)
-t I1 f (threshold I1 with integer value f)

imageops <option> OutputImageName is the run command where <option> can be one of the options described above.
