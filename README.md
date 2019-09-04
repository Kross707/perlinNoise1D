# perlinNoise1D


//perlinNoise1D.h is located inside "perlinNoise" folder (in case you want to use it directly rather than using visual studio)

A class for generating perlin noise and returning a vector storing it.
It provides a class and member methods: -

1)default constructor(literally of no use) : perlinNoise1D()
2)paramterised constructor : `perlinNoise1D(int size, double finalValue = 2, double initValue = 0)`
  size : represents the size of perlin noise array. If taken small, take as a multiple of 8...
  finalValue : represents the maximum possible value of elements of seed array. By default 2.
  initValue : represents the minimum possible value of elements of seed array. By default 0.

  NOTE : put finalValue first while function calling or runtime error would be thrown.
3)accessor function : `std::vector<double> getNoise()`
  returns the perlin noise array(final array). Must call parameterised constructor before this.
4)`plotArray()` plots the perlin noise array in an opengl glfw window. 
 
If you do not want to use opengl, just comment/remove the functions/libraries realted to it.

Moreover, this class also provides a bonus function `display(std::vector<double>)` which prints the passed vector :P .
  
Example usage(opengl and glfw must be configured in your system): -
 ```c++
 #include"perlinNoise1D.h"
  
  int main()
  {
    perlinNoise p(160);
    p.plotArray();
    return 0;
  }
```

Screenshots: -
![Image1](https://github.com/Kross707/perlinNoise1D/blob/master/snipNsketch/Annotation%202019-09-04%20223332.png)
![Image2](https://github.com/Kross707/perlinNoise1D/blob/master/snipNsketch/Annotation%202019-09-04%20223657.png)
![Image3](https://github.com/Kross707/perlinNoise1D/blob/master/snipNsketch/Annotation%202019-09-04%20223809.png)
