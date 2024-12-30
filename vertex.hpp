/*
 **************************** DO NOT EDIT THIS FILE ****************************
 ************ ANY CHANGES MADE WILL BE DISCARDED BEFORE EVALUATION *************
 */

#ifndef VERTEX_HPP
#define VERTEX_HPP

using namespace std;

// Vertex Class
class vertex {
	int id;
	char* subjectName; // for future use
	int color;
	// include other fields based on the scenario
public:
	// constructor to create a new vertex with an integer label 
	vertex(int);
	// constructor to create a new vertex with an integer label and name
	vertex(int, char*); 

	// getter functions
	int getId();
	char* getLabel();
	int getColor();

	// setter functions
	void setLabel(char*); // for future use
    void setColor(int); 
	// print function
	void print();
};

// Vertex Node Class 
class vertexNode {
	vertex* v;
	vertexNode* next;
public:
	vertexNode(vertex*); // create a node with a vertex object
	vertex* getVertex(); // get the vertex object from a vertex node
	vertexNode* getNext(); // get the next field of a vertex node
	void setNext(vertexNode*); // set the next field of a vertex node
	void print();
};

// Vertex List Class
class vertexList {
	vertexNode* head;
	int size;
public:
	vertexList(); // create empty vertex list
	vertexNode* getHead();
	int getSize();
	void addNode(vertexNode*);
	void print();
};


#endif