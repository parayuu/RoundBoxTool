#include "testApp.h"

//3Dview
//------------------------------------------------------------------------------------
void quadraticBezierVertex(float cpx, float cpy, float x, float y, float prevX, float prevY) {
    float cp1x = prevX + 2.0/3.0*(cpx - prevX);
    float cp1y = prevY + 2.0/3.0*(cpy - prevY);
    float cp2x = cp1x + (x - prevX)/3.0;
    float cp2y = cp1y + (y - prevY)/3.0;
    
    // finally call cubic Bezier curve function
    ofBezierVertex(cp1x, cp1y, cp2x, cp2y, x, y);
};

void quadraticBezierVertex(float cpx, float cpy, float x, float y, float prevX, float prevY, float z) {
    float cp1x = prevX + 2.0/3.0*(cpx - prevX);
    float cp1y = prevY + 2.0/3.0*(cpy - prevY);
    float cp2x = cp1x + (x - prevX)/3.0;
    float cp2y = cp1y + (y - prevY)/3.0;
    
    // finally call cubic Bezier curve function
    ofBezierVertex(cp1x, cp1y,z, cp2x, cp2y,z, x, y,z);
};


void roundedRect(float x, float y, float w, float h, float r) {
    ofBeginShape();
    ofVertex(x+r, y);
    ofVertex(x+w-r, y);
    quadraticBezierVertex(x+w, y, x+w, y+r, x+w-r, y);
    ofVertex(x+w, y+h-r);
    quadraticBezierVertex(x+w, y+h, x+w-r, y+h, x+w, y+h-r);
    ofVertex(x+r, y+h);
    quadraticBezierVertex(x, y+h, x, y+h-r, x+r, y+h);
    ofVertex(x, y+r);
    quadraticBezierVertex(x, y, x+r, y, x, y+r);
    ofEndShape();
}

void roundedBox(float x, float y, float w, float h, float r, float z) {
    ofBeginShape();
    ofVertex(x+r, y);
    ofVertex(x+w-r, y);
    quadraticBezierVertex(x+w, y, x+w, y+r, x+w-r, y);
    ofVertex(x+w, y+h-r);
    quadraticBezierVertex(x+w, y+h, x+w-r, y+h, x+w, y+h-r);
    ofVertex(x+r, y+h);
    quadraticBezierVertex(x, y+h, x, y+h-r, x+r, y+h);
    ofVertex(x, y+r);
    quadraticBezierVertex(x, y, x+r, y, x, y+r);
    ofEndShape();
    
    ofBeginShape();
    ofVertex(x+r, y,z);
    ofVertex(x+w-r, y,z);
    quadraticBezierVertex(x+w, y, x+w, y+r, x+w-r, y,z);
    ofVertex(x+w, y+h-r,z);
    quadraticBezierVertex(x+w, y+h, x+w-r, y+h, x+w, y+h-r,z);
    ofVertex(x+r, y+h,z);
    quadraticBezierVertex(x, y+h, x, y+h-r, x+r, y+h,z);
    ofVertex(x, y+r,z);
    quadraticBezierVertex(x, y, x+r, y, x, y+r,z);
    ofEndShape();
    
    ofBeginShape();
    ofVertex(x+r, y);
    ofVertex(x+w-r, y);
    ofVertex(x+w-r, y,z);
    ofVertex(x+r, y,z);
    ofVertex(x+r, y);
    ofEndShape();
    
    ofBeginShape();
    ofVertex(x+r, y+h);
    ofVertex(x+w-r, y+h);
    ofVertex(x+w-r, y+h,z);
    ofVertex(x+r, y+h,z);
    ofVertex(x+r, y+h);
    ofEndShape();
    
    ofBeginShape();
    ofVertex(x+w, y+r);
    ofVertex(x+w, y+h-r);
    ofVertex(x+w, y+h-r,z);
    ofVertex(x+w, y+r,z);
    ofVertex(x+w, y+r);
    ofEndShape();
    
    ofBeginShape();
    ofVertex(x, y+r);
    ofVertex(x, y+h-r);
    ofVertex(x, y+h-r,z);
    ofVertex(x, y+r,z);
    ofVertex(x, y+r);
    ofEndShape();
    
    ofBeginShape();
    ofVertex(x+w-r, y, 0);
    quadraticBezierVertex(x+w, y, x+w, y+r, x+w-r, y, 0);
    ofVertex(x+w, y+r,z);
    quadraticBezierVertex(x+w, y, x+w-r, y, x+w, y+r,z);
    ofVertex(x+w-r, y, 0);
    ofEndShape();
    
    ofBeginShape();
    ofVertex(x+w-r, y+h, 0);
    quadraticBezierVertex(x+w, y+h, x+w, y+h-r, x+w-r, y+h, 0);
    ofVertex(x+w, y+h-r,z);
    quadraticBezierVertex(x+w, y+h, x+w-r, y+h, x+w, y+h-r,z);
    ofVertex(x+w-r, y+h, 0);
    ofEndShape();
    
    ofBeginShape();
    ofVertex(x+r, y+h, 0);
    quadraticBezierVertex(x, y+h, x, y+h-r, x+r, y+h, 0);
    ofVertex(x, y+h-r,z);
    quadraticBezierVertex(x, y+h, x+r, y+h, x, y+h-r,z);
    ofVertex(x+r, y+h, 0);
    ofEndShape();
    
    ofBeginShape();
    ofVertex(x, y+r, 0);
    quadraticBezierVertex(x, y, x+r, y, x, y+r, 0);
    ofVertex(x+r, y,z);
    quadraticBezierVertex(x, y, x, y+r, x+r, y,z);
    ofVertex(x, y+r, 0);
    ofEndShape();
}

//--------------------------------------------------------------
void testApp::setup(){
    ofSetWindowShape(1200, 800);
    //ofEnableAlphaBlending();
    ofBackground(0);
    ofSetFrameRate(60);
    ofEnableSmoothing();
    
    
    //gui setup
    gui.setup("Box", 950, 0, 250, 580);
    gui.addPanel("1", 1);
    gui.setWhichPanel(0);
    gui.addSlider("Width   (mm)  ", "width", 50, 15, 200, true);
    gui.addSlider("Depth   (mm)  ", "depth", 50, 15, 200, true);
    gui.addSlider("Height  (mm)  ", "height", 50, 15, 200, true);
    gui.addSlider("Round   (mm)  ", "round", 10, 3, 50, true);
    gui.addSlider("Material \nThickness   (mm)  ", "thickness", 3, 0, 5, false);
    gui.addSlider("Joints_1    ", "joints1", 3, 3, 12, true);
    gui.addSlider("Joints_2    ", "joints2", 5, 5, 12, true);
    //gui.addSlider("Top_Joints2", "joints3", 5, 5, 12, true);
    gui.addSlider("Fit_Joint", "fit", 0.1, 0, 0.5, false);
    //gui.addToggle("Hole_Set", "hole_set", false);
    //gui.addSlider("Hole_Size", "hole_size", 3, 1, 5, false);
    gui.addSlider("Felt Thickness (mm)", "felt_thickness", 1, 1, 3, true);
    gui.addToggle("+Felt(inside)", "felt", false);
    gui.addToggle("+Decoration(outside)", "deco", false);
    gui.addToggle("ViewChange", "view_switch", false);
    gui.addPanel("2", 2);
    gui.setWhichPanel(1);
    gui.addSlider("k-b setting1 ", "d1", 30, 10, 50, false);
    gui.addSlider("k-b setting2 ", "d2", 5, 1, 20, false);
    gui.addSlider("k-b setting3 ", "d3", 1, 0.5, 3, false);
    
    

    
    //set viewport
    viewport.x = 0;
	viewport.y = 0;
	viewport.width = ofGetWindowWidth()-200;
	viewport.height = ofGetWindowHeight();
    view = false;
    
    space = 15;
    ofNoFill();
    ofSetColor(0, 0, 0);
    ofSetLineWidth(1);
    
    save = 0;
        
    //lighting setup
	light.setSpotlight();
	light.setPosition(-800, 800, 800);
	light.setAmbientColor(ofFloatColor(0.3, 0.1, 0.1, 1.0));
	light.setDiffuseColor(ofFloatColor(0.3, 0.3, 0.8));
	light.setSpecularColor(ofFloatColor(1.0, 1.0, 1.0));
    
    
 
}

//--------------------------------------------------------------
void testApp::update(){
    
    //----------------------------------------w,d,h,R setting-------
    width = gui.getValueI("width");
    depth = gui.getValueI("height");
    height = gui.getValueI("depth");
    thickness = gui.getValueF("thickness");
    feltthickness = gui.getValueI("felt_thickness");
    j1 = int(gui.getValueI("joints1")/2)*2 +1;
    j2 = int(gui.getValueI("joints2")/2)*2+1;
    //j3 = int(gui.getValueI("joints3")/2)*2+1;
    //hole_r = gui.getValueF("hole_size");
    rect_R = gui.getValueI("round");
    fit = gui.getValueF("fit");
    felt = gui.getValueB("felt");
    deco = gui.getValueB("deco");
    view = gui.getValueB("view_switch");
    
    d1 = gui.getValueF("d1");;
    d2 = gui.getValueF("d2");;
    d3 = gui.getValueF("d3");;
    
    bendNum = rects_bend.z / (2 * d3) ;
    
    d4 = rects_bend.z / (bendNum*2);
    
    lineNum = depth / (d1+d2) + 1.5;
  
    
    
    
    //----------------------------------------bend update-----
    bend_line1.clear();
    bend_line2.clear();
    
        for (int i = 0; i < lineNum;i++ ) {
        ofVec4f R;
        R.set(0,0,0,0);
        bend_line1.push_back(R);
        bend_line2.push_back(R);
    }

    //----------------------------------------rect position setting-----
    
    rects_1.x = 400 - width/2 + thickness;
    rects_1.y = 0 - height/2 + thickness -250;
    rects_1.z = width - thickness*2;
    rects_1.w = height - thickness*2;
    
    rects_2.x = 200;
    rects_2.y = 0 - depth/2 + thickness;
    rects_2.z = (width - (rect_R+thickness)*2);
    rects_2.w = depth - thickness*2;
    
    rects_bend.x = rects_2.z + 200;
    rects_bend.y = 0 - depth/2;
    rects_bend.z = (2 * rect_R * PI) / 4;
    rects_bend.w = depth;

        
    rects_3.x = (2 * rect_R * PI) / 4 + rects_2.z + 200;
    rects_3.y = 0 - depth/2 + thickness ;
    rects_3.z = height - 2 * (rect_R + thickness) ;
    rects_3.w = depth - thickness*2;
    
    //-------------------------Side_Joint position update
    joint_1.x = rects_3.x;
    joint_1.y = rects_3.y - thickness;
    joint_1.z = rects_3.z / j1;
    joint_1.w = thickness;
    
    joint_2.x = rects_1.x - thickness;
    joint_2.y = rects_1.y + rect_R + joint_1.z - fit/2;
    joint_2.z = thickness;
    joint_2.w = rects_3.z / j1 + fit;
    
    joint_3.x = rects_bend.x + rects_bend.z*2 + rects_3.z + joint_3.z;
    joint_3.y = rects_2.y - thickness;
    joint_3.z = rects_2.z / j2;
    joint_3.w = thickness;
    
    joint_4.x = rects_1.x + rect_R;
    joint_4.y = rects_1.y - thickness;
    joint_4.z = rects_2.z / j2;
    joint_4.w = thickness;
    
    joint_5.x = rects_2.x + joint_3.z;
    joint_5.y = rects_2.y - thickness;
    joint_5.z = rects_2.z / j2;
    joint_5.w = thickness;
    
    
    
    
    //----------------------------------------bend_line---
    for (int i = 0 ; i < lineNum; i++) {
        bend_line1[i].x = rects_bend.x;
        bend_line1[i].y = rects_bend.y + (d1 + d2)*i;
        bend_line1[i].z = rects_bend.x;
        bend_line1[i].w = d1 + bend_line1[i].y;
        
        bend_line2[i].x = bend_line1[i].x + d4;
        bend_line2[i].y = rects_bend.y + (d1 + d2)*i + (d1 + d2)/2;
        bend_line2[i].z = bend_line1[i].x + d4;
        bend_line2[i].w = d1 + bend_line2[i].y;
    }
    Q = ((d1+d2) * lineNum -d2 -depth) /2;
    //----------------------------------------3D view---
    
       //----------------------------------------3D Rotate----------
    if (Rotate > 360) {
        Rotate = 0;
    }else{
        //Rotate += 0.1;
    }
    
    
    //----------------------------------------GUI update---------------
    gui.update();
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackgroundGradient(0, 80,OF_GRADIENT_LINEAR);
    
    ofNoFill();
    ofSetColor(0, 0, 0);
    ofSetLineWidth(1);
    
    
    //----------------------------------------3D view---
    {
        // glEnable(GL_DEPTH_TEST);
   //light.enable();
       
    drawViewportOutline(viewport);
	camera.begin(viewport);
        camera.setDistance(300);
    
    //ofSetLineWidth(2);
    ofRotateX(-80);
    ofRotateY(0);
    ofRotateZ(Rotate);
     ofTranslate(-width/2, -height/2,-50 - depth/4);
    
        
        if (!view) {
         ofFill();
        ofSetColor(30, 200, 255);
        roundedBox(0,0 , width, height, rect_R, depth);
        
        ofNoFill();
        ofSetColor(230, 230, 230);
         roundedBox(0,0 , width, height, rect_R, depth);
        }
        
      //  light.disable();

        camera.end();
        
    }
    
    //----------------------------------------plan view------------
   
    if(view){
        ofBackground(240);
    //ofSetColor(<#int r#>, <#int g#>, <#int b#>)
    ofEnableSmoothing();
    ofPushMatrix();
    ofSetLineWidth(1);
    ofTranslate(0, ofGetWindowHeight()/2); //原点移動
    ofRectRounded(rects_1.x, rects_1.y, rects_1.z, rects_1.w, rect_R);
    ofRectRounded(rects_1.x + rects_1.z + 50, rects_1.y, rects_1.z, rects_1.w, rect_R);
    ofRect(rects_2.x + joint_5.z*2, rects_2.y, rects_2.z - joint_5.z*2, rects_2.w);
    ofRect(rects_bend.x, rects_bend.y, rects_bend.z, rects_bend.w);
    ofRect(rects_3.x, rects_3.y, rects_3.z, rects_3.w);
    
    
    ofRect(rects_bend.x + rects_bend.z + rects_3.z, rects_bend.y, rects_bend.z, rects_bend.w);
    ofRect(rects_bend.x + rects_bend.z*2 + rects_3.z, rects_2.y, rects_2.z, rects_2.w);
    ofRect(rects_bend.x + rects_bend.z*2 + rects_3.z + rects_2.z, rects_bend.y, rects_bend.z, rects_bend.w);
    ofRect(rects_bend.x + rects_bend.z*3 + rects_3.z + rects_2.z, rects_3.y, rects_3.z, rects_3.w);
    ofRect(rects_bend.x + rects_bend.z*3 + rects_3.z*2 + rects_2.z, rects_bend.y, rects_bend.z, rects_bend.w);
    
    ofRect(rects_bend.x + rects_bend.z*4 + rects_3.z*2 + rects_2.z, rects_2.y, joint_5.z*2, rects_2.w);
    
   
    
        //----------------------------------------bend Line------------

    for (int i = 0; i < lineNum; i++) {
        for (int j = 0; j < bendNum + 1; j++) {
            ofLine(bend_line1[i].x + j*d4*2 , bend_line1[i].y -Q, bend_line1[i].z + j*d4*2 , bend_line1[i].w -Q);
            ofLine(bend_line1[i].x + j*d4*2 +rects_3.z +rects_bend.z, bend_line1[i].y -Q, bend_line1[i].z + j*d4*2 +rects_3.z +rects_bend.z, bend_line1[i].w -Q);
            ofLine(bend_line1[i].x + j*d4*2 +rects_3.z +rects_bend.z*2 +rects_2.z, bend_line1[i].y -Q, bend_line1[i].z + j*d4*2 +rects_3.z +rects_bend.z*2 +rects_2.z, bend_line1[i].w -Q);
            ofLine(bend_line1[i].x + j*d4*2 +rects_3.z*2 +rects_bend.z*3 +rects_2.z, bend_line1[i].y -Q, bend_line1[i].z + j*d4*2 +rects_3.z*2 +rects_bend.z*3 +rects_2.z, bend_line1[i].w -Q);
            
            
            if (j<bendNum && i<lineNum-1) {
                ofLine(bend_line2[i].x + j*d4*2 , bend_line2[i].y -Q, bend_line2[i].z + j*d4*2 , bend_line2[i].w -Q);
                ofLine(bend_line2[i].x + j*d4*2 +rects_3.z +rects_bend.z, bend_line2[i].y -Q, bend_line2[i].z + j*d4*2 +rects_3.z +rects_bend.z, bend_line2[i].w -Q);
                ofLine(bend_line2[i].x + j*d4*2 +rects_3.z +rects_bend.z*2 +rects_2.z, bend_line2[i].y -Q, bend_line2[i].z + j*d4*2 +rects_3.z +rects_bend.z*2 +rects_2.z, bend_line2[i].w -Q);
                ofLine(bend_line2[i].x + j*d4*2 +rects_3.z*2 +rects_bend.z*3 +rects_2.z, bend_line2[i].y -Q, bend_line2[i].z + j*d4*2 +rects_3.z*2 +rects_bend.z*3 +rects_2.z, bend_line2[i].w -Q);
                
            }

        }
    }
    
   

    
    
    //----------------------------------------joint_parts 1~2------
    
    for (int i = 0; i < j1 / 2 +1; i++) {
        ofRect(joint_1.x + joint_1.z*i*2 , joint_1.y, joint_1.z, joint_1.w);
        ofRect(joint_1.x + joint_1.z*i*2 , joint_1.y + depth - thickness, joint_1.z, joint_1.w);
        
        ofRect(joint_1.x + joint_1.z*i*2 + rects_2.z + rects_3.z + rects_bend.z*2 , joint_1.y, joint_1.z, joint_1.w);
        ofRect(joint_1.x + joint_1.z*i*2 + rects_2.z + rects_3.z + rects_bend.z*2, joint_1.y + depth - thickness, joint_1.z, joint_1.w);
        
        if (i<j1/2) {
            ofRect(joint_2.x , joint_2.y + joint_1.z*i*2, joint_2.z, joint_2.w);
            ofRect(joint_2.x + rects_1.z + thickness, joint_2.y + joint_1.z*i*2, joint_2.z, joint_2.w);
            
            ofRect(joint_2.x + rects_1.z + 50, joint_2.y + joint_1.z*i*2, joint_2.z, joint_2.w);
            ofRect(joint_2.x + rects_1.z + thickness + rects_1.z + 50, joint_2.y + joint_1.z*i*2, joint_2.z, joint_2.w);
        }
    }
    
    for (int i = 0; i < j2 / 2 +1; i++) {
        ofRect(joint_4.x + joint_4.z*i*2, joint_4.y, joint_4.z, joint_4.w);
        ofRect(joint_4.x + joint_4.z*i*2, joint_4.y + rects_1.w + thickness, joint_4.z, joint_4.w);
        
        ofRect(joint_4.x + joint_4.z*i*2 + rects_1.z + 50, joint_4.y, joint_4.z, joint_4.w);
        ofRect(joint_4.x + joint_4.z*i*2 + rects_1.z + 50, joint_4.y + rects_1.w + thickness, joint_4.z, joint_4.w);
        

        
        if (i<j2/2) {
            ofRect(joint_3.x + joint_3.z*i*2 - fit/2, joint_3.y, joint_3.z+ fit, joint_3.w);
            ofRect(joint_3.x + joint_3.z*i*2 - fit/2, joint_3.y + depth - thickness, joint_3.z+ fit, joint_3.w);
            
            
            if (i!=0) {
                ofRect(joint_5.x + joint_5.z*i*2 - fit/2, joint_5.y, joint_5.z + fit, joint_5.w);
                ofRect(joint_5.x + joint_5.z*i*2 - fit/2, joint_5.y + depth - thickness, joint_5.z + fit, joint_5.w);
            }else if(i == 0){
                ofRect(joint_5.x  + rects_bend.z*4 + rects_3.z*2 + rects_2.z*2 -fit, joint_5.y, joint_5.z + fit, joint_5.w);
                ofRect(joint_5.x  + rects_bend.z*4 + rects_3.z*2 + rects_2.z*2 -fit, joint_5.y + depth - thickness, joint_5.z + fit, joint_5.w);
            }
                    }
    }
    //----------------------------------------measure_line ---------
    ofSetColor(150);
    
    ofRect(rects_3.x,  rects_3.y + rects_3.w + 30, rects_3.z, 30);
    ofRect(rects_2.x + joint_5.z*2,  rects_3.y + rects_3.w + 30, rects_2.z - joint_5.z*2, 30);
    ofRect(rects_bend.x + rects_bend.z*2 + rects_3.z, rects_3.y + rects_3.w + 30, rects_2.z, 30);
    ofRect(rects_bend.x + rects_bend.z*3 + rects_3.z + rects_2.z, rects_3.y + rects_3.w + 30, rects_3.z, 30);
    ofRect(rects_bend.x + rects_bend.z*4 + rects_3.z*2 + rects_2.z, rects_3.y + rects_3.w + 30, joint_5.z*2, 30);
    
    ofRect(rects_2.x + joint_5.z*2 -40, rects_2.y, 20, rects_2.w);
    //ofFill();
    
    
    string length1 = ofToString(rects_3.z);
    string length2 = ofToString(rects_2.z - joint_5.z*2);
    string length3 = ofToString(rects_2.z);
    string length4 = ofToString(rects_3.z);
    string length5 = ofToString(joint_5.z*2);
    string length6 = ofToString(rects_2.w);
    string mm = "(mm)";
    
    font.loadFont("arial.ttf", 8);
    font.drawString(length1, rects_3.x, rects_3.y + rects_3.w + 70+10);
    font.drawString(length2, rects_2.x + joint_5.z*2, rects_3.y + rects_3.w + 70);
    font.drawString(length3, rects_bend.x + rects_bend.z*2 + rects_3.z, rects_3.y + rects_3.w + 70);
    font.drawString(length4, rects_bend.x + rects_bend.z*3 + rects_3.z + rects_2.z, rects_3.y + rects_3.w + 70+10);
    font.drawString(length5, rects_bend.x + rects_bend.z*4 + rects_3.z*2 + rects_2.z, rects_3.y + rects_3.w + 70);
    font.drawString(mm, rects_bend.x + rects_bend.z*4 + rects_3.z*2 + rects_2.z + joint_5.z*2+30, rects_3.y + rects_3.w + 70+10);
    
    font.drawString(length6, rects_2.x + joint_5.z*2 -40, rects_2.y + rects_2.w + 15);
    
    ofFill();
    ofSetLineWidth(0);
    ofSetColor(240);
    
    
    ofRect(rects_2.x-10, rects_3.y + rects_3.w + 20, 1000, 30);
    ofRect(rects_2.x + joint_5.z*2 -30, rects_2.y -5, 15, rects_2.w +10);
    }else{}
    
    ofNoFill();
    ofSetColor(0, 0, 0);
    ofSetLineWidth(1);
    
    ofPopMatrix();
    //----------------------------------------hole---------------
    
    
    /*if (gui.getValueB("hole_set")) {
        ofCircle(hole_x, hole_y, hole_r);
        ofLine(hole_x , 0, hole_x , ofGetWindowHeight());
        ofLine(0, hole_y , ofGetWindowWidth(), hole_y);
    }*/
    
    //---------------------------------------saveAction---------
    if (save > 0) {
        ofFill();
        ofSetColor(240,save);
        ofSetLineWidth(0);
        
        ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
        
        save -= 3;
    }
    
    if (save<0) {
        save=0;
    }
    
    //----------------------------------------GUI draw---------------
    
    gui.draw();
    
    
    //----------------------------------------information-------------
    
    ofSetColor(150);
    string info = "FPS:" + ofToString(ofGetFrameRate())
        + "\n"
        + "\n" + "Inside Dimension (mm)"
        + "\n" + "   width : " + ofToString(width - thickness*2)
        + "\n" + "   depth : " + ofToString(height - thickness*2)
        + "\n" + "  height : " + ofToString(depth - thickness*2)
        + "\n"
        + "\n" + "[s] = save as .svg"
        + "\n" + "[g] = hide GUI Panel";
    ofDrawBitmapString(info, 10, 30);


}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == 'f') {
        //ofSetFullscreen(true);
        //gui.setup("Box", ofGetWindowWidth()-250, 0, 250, 580);
        //gui.setup("Box", ofGetWindowWidth()-250, 0, 250, 580);
    }
    
    if ( key == 'g' ) gui.hidden = !gui.hidden;
    
    
    
}

//--------------------------------------------------------------

void testApp::keyReleased(int key){
    //----------------------------------------svg export--------
    if (key == 's') {
        save=270;
        
        svg.addLayer("layer");
        
        svg.translate(0, 400);
        svg.fill("none");
        svg.stroke("#f00", 0.01);
        
        //--------
        svg.text("※グループ化されている展開図を[合体]してください", 200, 100);
        svg.text("(合成するオブジェクトを選択 → [ウィンドウ] → [パスファインダ] → [合体])", 200, 120);
        
        //-----------------------------Round_Rect_1-------------------------------

        svg.groupBegin();
        svg.rect(rects_1.x + rect_R, rects_1.y, rects_1.z - rect_R*2, rects_1.w);
        svg.rect(rects_1.x, rects_1.y +rect_R, rects_1.z, rects_1.w - rect_R*2);
        svg.circle(rects_1.x + rect_R, rects_1.y +rect_R, rect_R*2);
        svg.circle(rects_1.x  + rects_1.z - rect_R, rects_1.y +rect_R, rect_R*2);
        svg.circle(rects_1.x + rect_R, rects_1.y + rects_1.w - rect_R, rect_R*2);
        svg.circle(rects_1.x + rects_1.z - rect_R, rects_1.y + rects_1.w - rect_R, rect_R*2);
        
        for (int i = 0; i < j1 / 2 +1; i++) {
            if (i<j1/2) {
                svg.rect(joint_2.x , joint_2.y + joint_1.z*i*2, joint_2.z, joint_2.w);
                svg.rect(joint_2.x + rects_1.z + thickness, joint_2.y + joint_1.z*i*2, joint_2.z, joint_2.w);
                
            }
        }
        
        for (int i = 0; i < j2 / 2 +1; i++) {
            svg.rect(joint_4.x + joint_4.z*i*2, joint_4.y, joint_4.z, joint_4.w);
            svg.rect(joint_4.x + joint_4.z*i*2, joint_4.y + rects_1.w + thickness, joint_4.z, joint_4.w);
           
        }

        svg.groupEnd();
       
        //-----------------------------Round_Rect_2-------------------------------
        svg.groupBegin();
        svg.rect(rects_1.x + rect_R + rects_1.z + 50, rects_1.y, rects_1.z - rect_R*2, rects_1.w);
        svg.rect(rects_1.x + rects_1.z + 50, rects_1.y +rect_R, rects_1.z, rects_1.w - rect_R*2);
        svg.circle(rects_1.x + rect_R + rects_1.z + 50, rects_1.y +rect_R, rect_R*2);
        svg.circle(rects_1.x  + rects_1.z - rect_R + rects_1.z + 50, rects_1.y +rect_R, rect_R*2);
        svg.circle(rects_1.x + rect_R + rects_1.z + 50, rects_1.y + rects_1.w - rect_R, rect_R*2);
        svg.circle(rects_1.x + rects_1.z - rect_R + rects_1.z + 50, rects_1.y + rects_1.w - rect_R, rect_R*2);
        
        for (int i = 0; i < j1 / 2 +1; i++) {
            if (i<j1/2) {
                svg.rect(joint_2.x + rects_1.z + 50, joint_2.y + joint_1.z*i*2, joint_2.z, joint_2.w);
                svg.rect(joint_2.x + rects_1.z + thickness + rects_1.z + 50, joint_2.y + joint_1.z*i*2, joint_2.z, joint_2.w);
            }
        }
        
        for (int i = 0; i < j2 / 2 +1; i++) {
            svg.rect(joint_4.x + joint_4.z*i*2 + rects_1.z + 50, joint_4.y, joint_4.z, joint_4.w);
            svg.rect(joint_4.x + joint_4.z*i*2 + rects_1.z + 50, joint_4.y + rects_1.w + thickness, joint_4.z, joint_4.w);
            
        }
        svg.groupEnd();
        
        
        //-----------------------------Side_Rect-------------------------------
        svg.groupBegin();
        svg.rect(rects_2.x + joint_5.z*2, rects_2.y, rects_2.z - joint_5.z*2, rects_2.w);
        svg.rect(rects_bend.x, rects_bend.y, rects_bend.z, rects_bend.w);
        svg.rect(rects_3.x, rects_3.y, rects_3.z, rects_3.w);
        
        
        svg.rect(rects_bend.x + rects_bend.z + rects_3.z, rects_bend.y, rects_bend.z, rects_bend.w);
        svg.rect(rects_bend.x + rects_bend.z*2 + rects_3.z, rects_2.y, rects_2.z, rects_2.w);
        svg.rect(rects_bend.x + rects_bend.z*2 + rects_3.z + rects_2.z, rects_bend.y, rects_bend.z, rects_bend.w);
        svg.rect(rects_bend.x + rects_bend.z*3 + rects_3.z + rects_2.z, rects_3.y, rects_3.z, rects_3.w);
        svg.rect(rects_bend.x + rects_bend.z*3 + rects_3.z*2 + rects_2.z, rects_bend.y, rects_bend.z, rects_bend.w);
        
        svg.rect(rects_bend.x + rects_bend.z*4 + rects_3.z*2 + rects_2.z, rects_2.y, joint_5.z*2, rects_2.w);
        //---------
        
        //----------------------------------------joint_parts 1~2------
        
        for (int i = 0; i < j1 / 2 +1; i++) {
            svg.rect(joint_1.x + joint_1.z*i*2 , joint_1.y, joint_1.z, joint_1.w);
            svg.rect(joint_1.x + joint_1.z*i*2 , joint_1.y + depth - thickness, joint_1.z, joint_1.w);
            
            svg.rect(joint_1.x + joint_1.z*i*2 + rects_2.z + rects_3.z + rects_bend.z*2 , joint_1.y, joint_1.z, joint_1.w);
            svg.rect(joint_1.x + joint_1.z*i*2 + rects_2.z + rects_3.z + rects_bend.z*2, joint_1.y + depth - thickness, joint_1.z, joint_1.w);
            
        }
        
        for (int i = 0; i < j2 / 2 +1; i++) {
            if (i<j2/2) {
                svg.rect(joint_3.x + joint_3.z*i*2 - fit/2, joint_3.y, joint_3.z+ fit, joint_3.w);
                svg.rect(joint_3.x + joint_3.z*i*2 - fit/2, joint_3.y + depth - thickness, joint_3.z+ fit, joint_3.w);
                
                
                if (i!=0) {
                    svg.rect(joint_5.x + joint_5.z*i*2 - fit/2, joint_5.y, joint_5.z + fit, joint_5.w);
                    svg.rect(joint_5.x + joint_5.z*i*2 - fit/2, joint_5.y + depth - thickness, joint_5.z + fit, joint_5.w);
                }else if(i == 0){
                    svg.rect(joint_5.x  + rects_bend.z*4 + rects_3.z*2 + rects_2.z*2 -fit, joint_5.y, joint_5.z + fit, joint_5.w);
                    svg.rect(joint_5.x  + rects_bend.z*4 + rects_3.z*2 + rects_2.z*2 -fit, joint_5.y + depth - thickness, joint_5.z + fit, joint_5.w);
                }
            }
        }

        svg.groupEnd();
        
        //------------------------------------------bend_Line-------------------------------------------
        svg.groupBegin();
        
        for (int i = 0; i < lineNum; i++) {
            for (int j = 0; j < bendNum + 1; j++) {
                svg.line(bend_line1[i].x + j*d4*2 , bend_line1[i].y -Q, bend_line1[i].z + j*d4*2 , bend_line1[i].w -Q);
                svg.line(bend_line1[i].x + j*d4*2 +rects_3.z +rects_bend.z, bend_line1[i].y -Q, bend_line1[i].z + j*d4*2 +rects_3.z +rects_bend.z, bend_line1[i].w -Q);
                svg.line(bend_line1[i].x + j*d4*2 +rects_3.z +rects_bend.z*2 +rects_2.z, bend_line1[i].y -Q, bend_line1[i].z + j*d4*2 +rects_3.z +rects_bend.z*2 +rects_2.z, bend_line1[i].w -Q);
                svg.line(bend_line1[i].x + j*d4*2 +rects_3.z*2 +rects_bend.z*3 +rects_2.z, bend_line1[i].y -Q, bend_line1[i].z + j*d4*2 +rects_3.z*2 +rects_bend.z*3 +rects_2.z, bend_line1[i].w -Q);
                
                
                if (j<bendNum && i<lineNum-1) {
                    svg.line(bend_line2[i].x + j*d4*2 , bend_line2[i].y -Q, bend_line2[i].z + j*d4*2 , bend_line2[i].w -Q);
                    svg.line(bend_line2[i].x + j*d4*2 +rects_3.z +rects_bend.z, bend_line2[i].y -Q, bend_line2[i].z + j*d4*2 +rects_3.z +rects_bend.z, bend_line2[i].w -Q);
                    svg.line(bend_line2[i].x + j*d4*2 +rects_3.z +rects_bend.z*2 +rects_2.z, bend_line2[i].y -Q, bend_line2[i].z + j*d4*2 +rects_3.z +rects_bend.z*2 +rects_2.z, bend_line2[i].w -Q);
                    svg.line(bend_line2[i].x + j*d4*2 +rects_3.z*2 +rects_bend.z*3 +rects_2.z, bend_line2[i].y -Q, bend_line2[i].z + j*d4*2 +rects_3.z*2 +rects_bend.z*3 +rects_2.z, bend_line2[i].w -Q);
                    
                }
                
            }
        }
        
        
        svg.groupEnd();
        
        //------------------------------------------felt(inside)-------------------------------------------
        if (felt) {
            svg.groupBegin();
            svg.rect(rects_1.x + rect_R + rects_1.z + 550, rects_1.y, rects_1.z - rect_R*2, rects_1.w);
            svg.rect(rects_1.x + rects_1.z + 550, rects_1.y +rect_R, rects_1.z, rects_1.w - rect_R*2);
            svg.circle(rects_1.x + rect_R + rects_1.z + 550, rects_1.y +rect_R, rect_R*2);
            svg.circle(rects_1.x  + rects_1.z - rect_R + rects_1.z + 550, rects_1.y +rect_R, rect_R*2);
            svg.circle(rects_1.x + rect_R + rects_1.z + 550, rects_1.y + rects_1.w - rect_R, rect_R*2);
            svg.circle(rects_1.x + rects_1.z - rect_R + rects_1.z + 550, rects_1.y + rects_1.w - rect_R, rect_R*2);
            svg.groupEnd();
            
            svg.groupBegin();
            svg.rect(rects_1.x + rect_R + rects_1.z*2 + 600, rects_1.y, rects_1.z - rect_R*2, rects_1.w);
            svg.rect(rects_1.x + rects_1.z*2 + 600, rects_1.y +rect_R, rects_1.z, rects_1.w - rect_R*2);
            svg.circle(rects_1.x + rect_R + rects_1.z*2 + 600, rects_1.y +rect_R, rect_R*2);
            svg.circle(rects_1.x  + rects_1.z*2 - rect_R + rects_1.z + 600, rects_1.y +rect_R, rect_R*2);
            svg.circle(rects_1.x + rect_R + rects_1.z*2 + 600, rects_1.y + rects_1.w - rect_R, rect_R*2);
            svg.circle(rects_1.x + rects_1.z - rect_R + rects_1.z*2 + 600, rects_1.y + rects_1.w - rect_R, rect_R*2);
            svg.groupEnd();
            
            svg.groupBegin();
            svg.rect(rects_1.x + rect_R + rects_1.z + 550-rect_R, rects_2.y, rects_2.z*2 + rects_bend.z*4 + rects_3.z*2, rects_2.w - feltthickness*2);
            svg.groupEnd();

        }else{}
        
        //------------------------------------------Deco(outside)-------------------------------------------
        if (deco) {
            int deco_space;
            deco_space = 500;
            svg.groupBegin();
            svg.rect(rects_1.x + rect_R + rects_1.z + 550, rects_1.y - thickness +deco_space, rects_1.z - rect_R*2, rects_1.w + thickness*2);
            svg.rect(rects_1.x + rects_1.z + 550 - thickness, rects_1.y +rect_R +deco_space, rects_1.z + thickness*2, rects_1.w - rect_R*2);
            svg.circle(rects_1.x + rect_R + rects_1.z + 550, rects_1.y +rect_R +deco_space, rect_R*2+thickness*2);
            svg.circle(rects_1.x  + rects_1.z - rect_R + rects_1.z + 550, rects_1.y +rect_R +deco_space, rect_R*2+thickness*2);
            svg.circle(rects_1.x + rect_R + rects_1.z + 550, rects_1.y + rects_1.w - rect_R +deco_space, rect_R*2+thickness*2);
            svg.circle(rects_1.x + rects_1.z - rect_R + rects_1.z + 550, rects_1.y + rects_1.w - rect_R +deco_space, rect_R*2+thickness*2);
            svg.groupEnd();
            
            svg.groupBegin();
            svg.rect(rects_1.x + rect_R + rects_1.z*2 + 600, rects_1.y- thickness +deco_space, rects_1.z - rect_R*2, rects_1.w+ thickness*2);
            svg.rect(rects_1.x + rects_1.z*2 + 600- thickness, rects_1.y +rect_R +deco_space, rects_1.z+ thickness*2, rects_1.w - rect_R*2);
            svg.circle(rects_1.x + rect_R + rects_1.z*2 + 600, rects_1.y +rect_R +deco_space, rect_R*2+thickness*2);
            svg.circle(rects_1.x  + rects_1.z*2 - rect_R + rects_1.z + 600, rects_1.y +rect_R +deco_space, rect_R*2+thickness*2);
            svg.circle(rects_1.x + rect_R + rects_1.z*2 + 600, rects_1.y + rects_1.w - rect_R +deco_space, rect_R*2+thickness*2);
            svg.circle(rects_1.x + rects_1.z - rect_R + rects_1.z*2 + 600, rects_1.y + rects_1.w - rect_R +deco_space, rect_R*2+thickness*2);
            svg.groupEnd();
            
            svg.groupBegin();
            svg.rect(rects_1.x + rect_R + rects_1.z + 550-rect_R, rects_2.y +deco_space, rects_2.z*2 + rects_bend.z*4 + rects_3.z*2 + 2*thickness*PI, rects_2.w);
            svg.groupEnd();
            
        }else{}
        

        
        //-------------------------------------save window------------------
        
        ofFileDialogResult saveFileResult = ofSystemSaveDialog(ofGetTimestampString() , "Save your file");
        
        if (saveFileResult.bSuccess){
             svg.saveToFile(saveFileResult.getPath() + ".svg");
             
         }
         
        string savename;
        savename = "Box_"+ofToString(width)+"_"
                            +ofToString(height)+"_"
                            +ofToString(depth)+"_"
                            +ofToString(thickness)+".svg";
        
       
        
        
    }else{}
    
}

//--------------------------------------------------------------

void testApp::drawViewportOutline(const ofRectangle & viewport){
	ofPushStyle();
    ofNoFill();
	ofSetColor(230);
	ofSetLineWidth(0);
	//ofRect(viewport);
	ofPopStyle();
}


//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    if (x<900) {
        hole_x = x - 5;
        hole_y = y - 5;
    }else{
        hole_x = -100;
        hole_y = -100;
    }
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
     gui.mouseDragged(x, y, button);
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
     gui.mousePressed(x, y, button);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
     gui.mouseReleased();
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

    