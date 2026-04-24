import processing.serial.*;
import java.awt.event.KeyEvent;
import java.io.IOException;
Serial myPort; // defines Object Serial
// defubes variables
String angle="";
String distance="";
String data="";
String noObject;
float pixsDistance;
int iAngle;
int iDistance;
int index1=0;
int index2=0;
PFont orcFont;

void setup() {
  size (1920, 1080);
  smooth();
  myPort = new Serial(this,"COM3", 9600); // starts the serial communication
  myPort.bufferUntil('.');
}
void draw() {
  
  fill(98,245,31);
  // simulating motion blur and slow fade of the movimg line
  noStroke();
  fill(0,4);
  rect(0, 0, width, 1010);
  
  fill(98,245,31); // green color
  // calls the function for drawing the radar
  drawRadar();
  drawLine();
  drawObject();
  drawText();
}
void serialEvent (Serial myPort) { // starts reading data from the Serial Port

  // reads the data from the Serial Port up to the Character '.' and puts it into the String variable "data"
  data = myPort.readStringUntil('.');
  data = data.substring(0,data.length()-1);
  
  index1 = data.indexOf(","); // find the character ','and put it into the variable "index1"
   angle= data.substring(0, index1);
  distance= data.substring(index1+1, data.length());
  
  // converts the String variables into Integer
  iAngle = int(angle);
  iDistance = int(distance);
}
void drawRadar() {
  pushMatrix();
  translate(960,500); // moves the starting coordinates to a new location
  noFill();
  strokeWeight(2);
  stroke(98,245,31);
  // draw the circle lines
  circle(0,0,200);
  circle(0,0,400);
  circle(0,0,600);
  circle(0,0,800);
  circle(0,0,1000);
  
  // draw the angle lines
  
  line(0,0,-500*cos(radians(30)),-500*sin(radians(30)));
  line(0,0,-500*cos(radians(60)),-500*sin(radians(60)));
  line(0,0,-500*cos(radians(90)),-500*sin(radians(90)));
  line(0,0,-500*cos(radians(120)),-500*sin(radians(120)));
  line(0,0,-500*cos(radians(150)),-500*sin(radians(150)));
  line(0,0,-500*cos(radians(210)),-500*sin(radians(210)));
  line(0,0,-500*cos(radians(240)),-500*sin(radians(240)));
  line(0,0,-500*cos(radians(270)),-500*sin(radians(270)));
  line(0,0,-500*cos(radians(300)),-500*sin(radians(300)));
  line(0,0,-500*cos(radians(330)),-500*sin(radians(330)));
  line(0,0,-500*cos(radians(360)),-500*sin(radians(360)));
  
  line(-580*cos(radians(30)),0,500,0);
  popMatrix();
}


void drawObject() {
  pushMatrix();
  translate(960,500); // moves the starting coordinats to new location
  strokeWeight(15);
  stroke(255,10,10); // red color
  pixsDistance = iDistance*10; // covers the distance from the sensor from cm to pixels
  
  if(iDistance<50){
    // draws the object according to the angle and the distance
  point(pixsDistance*cos(radians(iAngle*-1)),-pixsDistance*sin(radians(iAngle*-1)));
  }
  popMatrix();
}
void drawLine() {
  pushMatrix();
  strokeWeight(5);
  stroke(30,250,60);
  translate(960,500); // moves the starting coordinats to new location
  line(0,0,500*cos(radians(iAngle*-1)),-500*sin(radians(iAngle*-1))); // darws the line according to the angle
  popMatrix();
}
void drawText() {
  pushMatrix();
  if(iDistance>50) {
    noObject = "";
  }
  else {
  noObject = "Object detected";
  }
  fill(0,0,0);
  noStroke();
  rect(0, 1010, width, 1080);
  fill(98,245,31);
  textSize(15);
  text("10cm",1010,490);
  text("20cm",1110,490);
  text("30cm",1210,490);
  text("40cm",1310,490);
  text("50cm",1410,490);
  textSize(30);
  text("" + noObject, 240, 1045);
  text("Angle: " + iAngle +" °", 1050,1045);
  text("Distance: ", 1380, 1045);
  if(iDistance<50) {
  text("        " + iDistance +" cm", 1500, 1045);
  }
  
  textSize(25);
  fill(98,245,60);
  translate(960+500*cos(radians(30)),500-500*sin(radians(30)));
  rotate(-radians(-60));
  text("60°",0,0);
  resetMatrix();
  translate(960+500*cos(radians(60)),500-500*sin(radians(60)));
  rotate(-radians(-30));
  text("30°",0,0);
  resetMatrix();
  translate(960+500*cos(radians(90)),990-960*sin(radians(90)));
  rotate(radians(0));
  text("0°",0,0);
  resetMatrix();
  translate(960+500*cos(radians(120)),500-500*sin(radians(120)));
  rotate(radians(-30));
  text("330°",0,0);
  resetMatrix();
  translate(960+500*cos(radians(150)),500-500*sin(radians(150)));
  rotate(radians(-60));
  text("300°",0,0);
  translate(450-500*cos(radians(30)),750+500*sin(radians(30)));
  rotate(-radians(+180));
  text("120°",0,0);
  resetMatrix();
  translate(960+500*cos(radians(60)),500+500*sin(radians(60)));
  rotate(-radians(-150));
  text("150°",0,0);
  resetMatrix();
  translate(960-970*cos(radians(90)),500+500*sin(radians(90)));
  rotate(radians(-180));
  text("180°",0,0);
  resetMatrix();
  translate(960+500*cos(radians(240)),500-500*sin(radians(240)));
  rotate(radians(+210));
  text("210°",0,0);
  resetMatrix();
  translate(960+500*cos(radians(150)),500+500*sin(radians(150)));
  rotate(radians(+240));
  text("240°",0,0);
  resetMatrix();
  translate(460,500);
  rotate(radians(-90));
  text("270°",0,0);
  resetMatrix();
  translate(1462,500);
  rotate(radians(+90));
  text("90°",0,0);
  popMatrix();
}
  
  
  
  
  
  
  
  
  
    
  
  
  



  
 
  

  
