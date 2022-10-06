void setup()
{
pinMode(13,OUTPUT);
pinMode(2,INPUT);
Serial.begin(9600);
}
int prev=0;
void loop()
{
if(digitalRead(2)==HIGH){
digitalWrite(13,HIGH);
if(prev==0){
Serial.write(1);
Serial.println(1);
prev=1;
}
}else{
digitalWrite(13,LOW);
if(prev==1){
Serial.println(0);
Serial.write(0);
prev=0;
}
}
}
//////////////////////////////////////
///////////anrgy bird/////////////////
import processing.serial.*;
Serial myPort;
int val;
import gifAnimation.*;
PImage[] animation;
Gif loopingGif, gpig;
import ddf.minim.*;
AudioPlayer player;
Minim minim;
int x=10,y=10;
boolean pause = false;
int up =0,right=0,left=0,down=0;
char prev='0';

public void setup(){

String portName= "COM3";
myPort = new Serial(this,portName,9600);
size(800,400);
frameRate(100);
println("gifAnimation"+Gif.version());
loopingGif = new Gif(this, "angrybirds.gif");
loopingGif.loop();
minim = new Minim(this);
player = minim.loadFile("title theme.mp3",2048);
gpig = new Gif(this,"pigs.gif");
gpig.loop();
}
void keyPressed(){
if(keyCode==UP)up=1;
if(keyCode==RIGHT)right=1;
if(keyCode==DOWN)down=1;
if(keyCode==LEFT)left=1;

if(key ==' '){
if(pause){
loopingGif.play();
pause = false;
}else{
loopingGif.pause();
pause = true;
}
}
if(key =='p'||key =='P'){
if(pause){
player.close();
pause = false;
}else {
player.close();
pause = true;
}
}
}
void keyReleased(){
if(keyCode==UP)up=0;
if(keyCode==RIGHT)right=0;
if(keyCode==DOWN)down=0;
if(keyCode==LEFT)left=0;
}
void stop(){
player.close();
minim.stop();
super.stop();
}
void draw(){
PImage b;
b = loadImage("angry.jpg");
background(b);

image(loopingGif,10+x,y+100);
if(myPort.available()>0){
val = myPort.read();
}
if(right==1)x+=6;
if(up==1)y-=2;
if(left==1)x-=6;
if(down==1)y+=2;

if(val =='1'&&prev=='0'){
x+=10;
prev='1';
}else if(val =='0'&&prev=='1'){
x+=10;
prev='0';
}
if(x>=200&&x<500){
PImage p;
p = loadImage("angry2.png");
background(p);
image(gpig,10+x,y+100);
player.play();
}
if(x>510){
PImage k;
k = loadImage("win.jpg");
background(k);
}

}
////////////////////////////
////////flappy bird/////////
import processing.serial.*;
import gifAnimation.*;
import ddf.minim.*;
Serial myPort;

int val;
PImage[] animation;
Gif loopingGif,gpig;

AudioPlayer player = null ;
Minim minim;

int x=20, y=110;
boolean pause = false;
boolean music_pause,loop_pause = false;
int up=0, down=0, left=0, right=0;
char prev= '0';

int i=0, j=0,k=-500,l=0;
int xb, yb, xc;
int lastState=4;

public void setup() {

minim = new Minim(this);
//String portName ="COM8";
//myPort = new Serial(this, portName, 115200);
size(800, 600);
frameRate(100);
println("gifAnimation " + Gif.version());
loopingGif = new Gif(this, "angrybirds.gif");
loopingGif.loop();
player = minim.loadFile("title theme.mp3", 2048);
gpig = new Gif(this, "pigs.gif");
gpig.loop();
player.play();
}


void draw() {

frameRate(10);
PImage b;
b = loadImage("bg.png");
image(b, i, 0);

i=i-10;
if (i <= -800)
{
i = 0;
}

image(b, 800+i, 0);

y=y+10;

PImage c;
c = loadImage("block.png");

j=j-10;

if (j <= -800)
{
j = 0;
}

k=k-10;

if (k <= -1600)
{
k = -500 + l * 300;
l++;
}

xb=800+j;
xc=1600+k;
image(c, xb, 0);
image(c, xb, 50);
image(c, xb, 100);
image(c, xb, 150);
//---------------------------------------------------
image(c, xb, 400);
image(c, xb, 450);
image(c, xb, 500);
image(c, xb, 550);

image(c, xc, 0);
image(c, xc, 50);
image(c, xc, 100);
image(c, xc, 150);
image(c, xc, 200);
image(c, xc, 250);
image(c, xc, 300);
image(c, xc, 350);
//---------------------------------------------------

//if ( myPort.available() > 0) { // If data is available,
// val = myPort.read(); // read it and store it in val
//}
// image(loopingGif, 0, 0);

if (up==1)y=y-20;
if (right==1)x=x+10;
if (down==1)y++;
if (left==1)x=x-10;

image(loopingGif, x, y);

//---------------------------------------------------
if (x >=510)
{
PImage k;
k = loadImage("win2.jpg");
background(k);
stop();
}

if (y <= 0 || y >= 550 )
{
PImage j;
j = loadImage("gameover.jpg");
background(j);
stop();
}

if (x >= xb-90 && x <= xb-40)
{
if (y <= 180)
{
PImage j;
j = loadImage("gameover.jpg");
background(j);

stop();
}
}
//---------------------------------------------------
if (x >= xb-90 && x <= xb-40)
{
if (y >= 320)
{
PImage j;
j = loadImage("gameover.jpg");
background(j);

stop();
}
}

//---------------------------------------------------
if (x >= xc-90 && x <= xc-40)
{
if (y <= 380)
{
PImage j;
j = loadImage("gameover.jpg");
background(j);

stop();
}
}
//---------------------------------------------------
}


void keyPressed() {
if (keyCode==UP)up=1;
if (keyCode==RIGHT)right=1;
if (keyCode==DOWN)down=1;
if (keyCode==LEFT)left=1;

if (key == 32) {
if (loop_pause) {
loop();
loopingGif.play();
loop_pause = false;
} else {
noLoop();
loopingGif.pause();
loop_pause = true;
}
}

if (key == 'p'||key == 'P') {
if (music_pause) {
player.play();
music_pause = false;
} else {
player.pause();
music_pause = true;
}
}
}


void keyReleased() {
if (keyCode==UP)
up=0;
if (keyCode==RIGHT)
right=0;
if (keyCode==DOWN)
down=0;
if (keyCode==LEFT)
left=0;
}


void stop()
{
// always close Minim audio classes when you are done with them
player.close();
minim.stop();
super.stop();
}
