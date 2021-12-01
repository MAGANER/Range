# Range
Header-only library to incapsulate for-cycles of numeric progressions.

Without Range:<br>
```c++
  for(int i = 0;i<10;i++)
  {
    //do someting
  }
  ```
  
With Range:<br>
  Example 1(moving forward):<br>
  ```c++
    for(auto n:Range<int>(0,10,1)
    {
      //do something
    }
  ```
  Example 2(moving backward):<br>
  ```c++
    for(auto n:Range<int>(10,0,1)
    {
      //do something
    }
  
 ```
 
 First and second arguments are begin and end [begin;end). The last one is step of progression.
    
    
