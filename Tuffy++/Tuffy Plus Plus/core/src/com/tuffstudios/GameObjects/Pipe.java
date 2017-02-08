package com.tuffstudios.GameObjects;
import com.badlogic.gdx.math.Intersector;
import com.badlogic.gdx.math.Rectangle;
import java.util.Random;

public class Pipe extends Scrollable {
	private Random r;
	private Rectangle bodyUp, bodyDown, barUp, barDown;
	public static final int VERTICAL_GAP = 45;
	public static final int BODY_WIDTH = 24;
	public static final int BODY_HEIGHT = 11;
	private float groundY;
	private boolean isScored = false;

	// When Pipe's constructor is invoked, invoke the super (Scrollable)
	// constructor
	public Pipe(float x, float y, int width, int height, float scrollSpeed, float groundY) {
		super(x, y, width, height, scrollSpeed);
		// Initialize a Random object for Random number generation
		r = new Random();
		bodyUp = new Rectangle();
		bodyDown = new Rectangle();
		barUp = new Rectangle();
		barDown = new Rectangle();
		this.groundY = groundY;
	}

	@Override
	public void update(float delta) {
		// Call the update method in the superclass (Scrollable)
		super.update(delta);

		// The set() method allows you to set the top left corner's x, y
		// coordinates,
		// along with the width and height of the rectangle
		barUp.set(position.x, position.y, width, height);
		barDown.set(position.x, position.y + height + VERTICAL_GAP, width, groundY - (position.y + height + VERTICAL_GAP));

		// Our body width is 24. The bar is only 22 pixels wide. So the body
		// must be shifted by 1 pixel to the left (so that the body is centered
		// with respect to its bar).
		// This shift is equivalent to: (BODY_WIDTH - width) / 2
		bodyUp.set(position.x - (BODY_WIDTH - width) / 2, position.y + height - BODY_HEIGHT, BODY_WIDTH, BODY_HEIGHT);
		bodyDown.set(position.x - (BODY_WIDTH - width) / 2, barDown.y, BODY_WIDTH, BODY_HEIGHT);
	}

	@Override
	public void reset(float newX) {
		// Call the reset method in the superclass (Scrollable)
		super.reset(newX);
		// Change the height to a random number
		height = r.nextInt(90) + 15;
		isScored = false;
	}

	public void onRestart(float x, float scrollSpeed) {
		velocity.x = scrollSpeed;
		reset(x);
	}

	public Rectangle getBodyUp() {
		return bodyUp;
	}

	public Rectangle getBodyDown() {
		return bodyDown;
	}

	public Rectangle getBarUp() {
		return barUp;
	}

	public Rectangle getBarDown() {
		return barDown;
	}

	public boolean collides(Elephant elephant) {
		if (position.x < elephant.getX() + elephant.getWidth()) {
			return (Intersector.overlaps(elephant.getBoundingCircle(), barUp) ||
					Intersector.overlaps(elephant.getBoundingCircle(), barDown) ||
					Intersector.overlaps(elephant.getBoundingCircle(), bodyUp) ||
					Intersector.overlaps(elephant.getBoundingCircle(), bodyDown));
		}
		return false;
	}

	public boolean isScored() {
		return isScored;
	}

	public void setScored(boolean b) {
		isScored = b;
	}
}
