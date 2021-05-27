There are several parts of Eternia Library that require intense optimization. 

For example, several math functions are using Taylor's series for estimating 
Power, Log and trigonometry functions. This wouldn't be an issue, but several 
functions like cosine, tangent, etc. all have these nested Taylor's series 
instead of directly implemented their own versions. Or perhaps using a more 
efficient mathematical algorithm would be wiser.
