class Point  //点 
{
   public double x,y;
   public Point(double x,double y)
   {
      this.x=x;
      this.y=y;       
   }      
}


class Line   //线 
{
    public Point x,y;
    public Line(double x1,double y1,double x2,double y2)
    {
       x.Point(x1,y1);
       y.Point(x2,y2);
    }
}

class Polygon   //多边形 
{   
    public Line[] line;
    public Polygon(double...coord) 
    {        
         for(Line element:line)
            element=new Line();    
    }    
}

class Square extends Polygon   //方形 
{
     public Square()
     {
        super(Line p[4]);       
     }     
}


class Triangle extends Polygon   //三角形 
{
   public Triangle() 
   {
      super(Line p[3]);       
   }     
} 

class Circle    //圆 
{
   public Point x;
   double r;
   public Circle(double x,double y,double r)
   {
        this.x.Point(x,y);
        this.r=r;  
   }    
}

class Ellipse   //椭圆 
{
     double semi-major,semi-minor;
     public Point x;
     public Ellipse(double x,double y,double a,double b)
     {
         this.x.Point(x,y);
         semi-major=a;
         semi-minor=b;       
     }   
}
