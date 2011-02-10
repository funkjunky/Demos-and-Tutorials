package {
	import flash.events.*;
	import flash.ui.Keyboard;
	import keyStruct;
	
public class game {
	var paddle1;
	var paddle2;
	var ball;
	var boundary;
	
	var pSpeed=5;
	var xSpeed=pSpeed;
	var ySpeed=pSpeed;
	
	private var keys:keyStruct = new keyStruct();
	
	public function game(p1,p2,b,by)
	{
		paddle1 = p1;
		paddle2 = p2;
		ball = b;
		boundary = by;
	}
	
	public function registerKeyDown(e:KeyboardEvent):void
	{
		switch(e.keyCode)
		{
			case Keyboard.UP:
				keys.up = true; break;
			case Keyboard.DOWN:
				keys.down = true; break;
			case Keyboard.RIGHT:
				keys.right = true; break;
			case Keyboard.LEFT:
				keys.left = true; break;
		}
	}
	public function registerKeyUp(e:KeyboardEvent):void
	{
		switch(e.keyCode)
		{
			case Keyboard.UP:
				keys.up = false; break;
			case Keyboard.DOWN:
				keys.down = false; break;
			case Keyboard.RIGHT:
				keys.right = false; break;
			case Keyboard.LEFT:
				keys.left = false; break;
		}
	}
	public function updateFromKeys():void {
		if(keys.up)
			paddle1.y-=pSpeed;
		if(keys.down)
			paddle1.y+=pSpeed;
		if(keys.right)
			paddle2.y-=pSpeed;
		if(keys.left)
			paddle2.y+=pSpeed;
	}
	
	public function gameLoop(e:Event):void {
		updateFromKeys();
		if((ball.x+= xSpeed) < boundary.x 
				|| ball.x > (boundary.x+boundary.width-ball.width))
			xSpeed *= -1;
		if((ball.y+= ySpeed) < boundary.y
				|| ball.y > (boundary.y+boundary.height-ball.height))
			ySpeed *= -1;
	}
}
}
