# Card Flip Memory Game 

### prog 1089 assignment 

## Objectives
* Use the MVC pattern 
* All game logic must be in the model
 


## Guidelines
* To be submitted to github
* Must follow MVC pattern
	* clicking on a button should update the model, not the view
	* after the model has been updated you should refresh the view by calling draw() 
	* The Model should know nothing about the view
	* The View should know nothing about the Model
	* Don’t forget comments and style. 
* All identifier names must be meaningful. 
	* Someone not familiar with your code should be able to read it and easily understand how it works. 
	* If you can’t achieve this with meaningful names and short functions, add comments. 

* You must display the current **score** as the user plays (it is possible to have a negative score).  
* You must have a **NEW GAME** button that zeros out the score and starts a new game.  

## Instructions

### Play
* The game starts by dealing 36 cards (the number of cards in your game is up to you). 
* The cards are shown face up for 4 seconds, giving the player a chance to memorize them. 
* The cards are all turned face down after 4 seconds, or when the user clicks on a card, whichever happens first. 
* Clicking on a face down card turns it face up
* Clicking on a face up card turns it face down
 
### Matching cards
* When you click on a face down card and there is currently a face up card the game tries to match the two cards. 
* Two cards match if they have the same Face, or if they have the same suit
* If the cards **do match**, 
	* both cards are turned face up and marked as “matched”
	* Matched cards are displayed with the cardfrontGrey background. 
	* Matched cards are always displayed face up
	* Clicking on a matched card does not change the state of the game in any way. 
* If the cards **don’t match** 
	* the card that was face up is turned face down, 
	* the card that was face down is turned face up
	

### Scoring	
* Matching Faces scores 9 points
* Matching Suits scores 3 points
* Flipping a card costs 1 point


