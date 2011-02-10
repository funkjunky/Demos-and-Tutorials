#ifndef GLUTM_WINDOW_H
#define GLUTM_WINDOW_H

/*

  GLT OpenGL C++ Toolkit (LGPL)
  Copyright (C) 2000-2002 Nigel Stewart  

  Email: nigels@nigels.com   
  WWW:   http://www.nigels.com/glt/

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/

/*!	\file 
	\brief   GLUT Window Class
	\ingroup GlutMaster
*/

#include <glutm/config.h>
#include <glutm/glut.h>
#include <glutm/menu.h>

#include <glt/viewport.h>

#include <string>

class GlutMaster;

// These are here for the benefit of derived classes that
// want to use the same default arguments for constructors

const std::string  titleDefault("GlutMaster");
const int          widthDefault       = 400;
const int          heightDefault      = 400;
const int          xDefault           = 10;
const int          yDefault           = 10;
const unsigned int displayModeDefault = GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE | GLUT_STENCIL;

///////////////////////////// GlutWindow ///////////////////////////////////////

/*! \class   GlutWindow 
    \brief   GLUT window base class
	\ingroup GlutMaster
	\author  Nigel Stewart (nigels@nigels.com)
*/

class GlutWindow
{
	friend class GlutMaster;

	#ifdef GLUTM_SAVER
	friend LRESULT WINAPI ScreenSaverProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);
	#endif

public:
	/*! 
		\brief		Constructor
		\param		title			Window title text
		\param		width			Window width
		\param		height			Window height
		\param		x				Window x Position
		\param		y				Window y Position
		\param		displayMode		OpenGL display mode

		Display mode can be a combination of 
		<table>
		<tr><td><b>GLUT_RGB    </b></td><td> True color RGB mode</td></tr>
		<tr><td><b>GLUT_RGBA   </b></td><td> True color RGBA mode</td></tr>
		<tr><td><b>GLUT_ALPHA  </b></td><td> Alpha color buffer component</td></tr>
		<tr><td><b>GLUT_INDEX  </b></td><td> Indexed color mode</td></tr>
		<tr><td><b>GLUT_SINGLE </b></td><td> Single buffered</td></tr>
		<tr><td><b>GLUT_DOUBLE </b></td><td> Double buffered</td></tr>
		<tr><td><b>GLUT_DEPTH  </b></td><td> Depth buffer</td></tr>
		<tr><td><b>GLUT_STENCIL</b></td><td> Stencil buffer</td></tr>
		<tr><td><b>GLUT_ACCUM  </b></td><td> Accumulation buffer</td></tr>
		<tr><td><b>GLUT_STEREO </b></td><td> Stereo mode</td></tr>
		</table>
	*/
	GlutWindow
	(
		const std::string &title       = titleDefault,
		const int          width       = widthDefault, 
		const int          height      = heightDefault,
		const int          x           = xDefault, 
		const int          y           = yDefault,
		const unsigned int displayMode = displayModeDefault
	);

	/// Destructor
	virtual ~GlutWindow();

	//
	// Callback Functions
	// (Derived classes should implement some of these)
	//

	/*! 
		\brief		Handler for window open event(s)
		\note		Implement your own OpenGL initialisation here
	*/
	virtual void OnOpen();
	/*! 
		\brief		Handler for window close event(s)
		\note		Implement your own OpenGL shutdown/cleanup here
	*/
	virtual void OnClose();
	/*! 
		\brief		Handler for window draw events
		\note		Implement your own OpenGL drawing here
	*/
	virtual void OnDisplay();
	/*! 
		\brief		Handler for tick events, if enabled
		\note		This is gentler on CPU load than the idle callback
	*/
	virtual void OnTick();
	/*! 
		\brief		Handler for idle events, if enabled
		\note		Use of idle tends to be a CPU hog
	*/
	virtual void OnIdle();
	/*! 
		\brief		Handler for timer events
		\note		Queue timer events via GlutWindow::setTimer()
	*/
	virtual void OnTimer(unsigned char val);
	/// Handler for keyboard events
	virtual void OnKeyboard(unsigned char key, int x, int y);
	/// Handler for keyboard-up events
	virtual void OnKeyboardUp(unsigned char key, int x, int y);
	/// Handler for special keyboard events (function keys, etc)
	virtual void OnSpecial(int key, int x, int y);   
	/// Handler for special keyboard-up events
	virtual void OnSpecialUp(int key, int x, int y);   
	/// Handler for mouse button events
	virtual void OnMouse(int button, int state, int x, int y);
	/// Handler for mouse movement events
	virtual void OnMotion(int x, int y);
	/// Handler for passive mouse motion events (no button pressed)
	virtual void OnPassiveMotion(int x, int y);

	/*!
		\brief Handler for mouse entry/leave events
	
		The state callback parameter is either <b>GLUT_LEFT</b> 
		or <b>GLUT_ENTERED</b> depending on if the mouse
		pointer has last left or entered the window.
		
		\note Some window systems may not generate accurate enter/leave callbacks.
	*/
	virtual void OnEntry(int state);

	/// Handler for menu events
	virtual void OnMenu(int value);
	/// Handler for window reshape events
	virtual void OnReshape(int w, int h);
	/// Handler for window visibility events
	virtual void OnVisibility(int visible);

	//
	// Window manipulation
	//

	/*! 
		\brief		Open the window
		\note		Window will receive OnOpen() event
		\note		Window opens automatically, but can be re-opened after close()
	*/
	void open();
	/*! 
		\brief		Grab an existing GLUT window
		\note		Old GlutWindow will receive OnClose() event
		\note		New GlutWindow will receive OnOpen() event
	*/
	void grab(const GlutWindow &window);
	/*! 
		\brief		Close the window
		\note		Window will receive OnClose() event
	*/
	void close();
	/*! 
		\brief		Position the window
		\note		Window will receive OnReshape() event
	*/
	void position(int x,int y);
	/*! 
		\brief		Reshape (resize) the window
		\note		Window will receive OnReshape() event
	*/
	void reshape(int width,int height);
	
	/*! 
		\brief		Set window cursor
		\param		cursor			Cursor type

		Cursor may be one of
		<table>
		<tr><td>GLUT_CURSOR_RIGHT_ARROW		</td><td>Arrow pointing up and to the right.	</td></tr>
		<tr><td>GLUT_CURSOR_LEFT_ARROW		</td><td>Arrow pointing up and to the left.	</td></tr>
		<tr><td>GLUT_CURSOR_INFO		</td><td>Pointing hand.				</td></tr>
		<tr><td>GLUT_CURSOR_DESTROY		</td><td>Skull & cross bones.			</td></tr>
		<tr><td>GLUT_CURSOR_HELP		</td><td>Question mark.				</td></tr>
		<tr><td>GLUT_CURSOR_CYCLE		</td><td>Arrows rotating in a circle.		</td></tr>
		<tr><td>GLUT_CURSOR_SPRAY		</td><td>Spray can.				</td></tr>
		<tr><td>GLUT_CURSOR_WAIT		</td><td>Wrist watch.				</td></tr>
		<tr><td>GLUT_CURSOR_TEXT		</td><td>Insertion point cursor for text.	</td></tr>
		<tr><td>GLUT_CURSOR_CROSSHAIR		</td><td>Simple cross-hair.			</td></tr>
		<tr><td>GLUT_CURSOR_UP_DOWN		</td><td>Bi-directional pointing up & down.	</td></tr>
		<tr><td>GLUT_CURSOR_LEFT_RIGHT		</td><td>Bi-directional pointing left & right.	</td></tr>
		<tr><td>GLUT_CURSOR_TOP_SIDE		</td><td>Arrow pointing to top side.		</td></tr>
		<tr><td>GLUT_CURSOR_BOTTOM_SIDE		</td><td>Arrow pointing to bottom side.		</td></tr>
		<tr><td>GLUT_CURSOR_LEFT_SIDE		</td><td>Arrow pointing to left side.		</td></tr>
		<tr><td>GLUT_CURSOR_RIGHT_SIDE		</td><td>Arrow pointing to right side.		</td></tr>
		<tr><td>GLUT_CURSOR_TOP_LEFT_CORNER	</td><td>Arrow pointing to top-left corner.	</td></tr>
		<tr><td>GLUT_CURSOR_TOP_RIGHT_CORNER	</td><td>Arrow pointing to top-right corner.	</td></tr>
		<tr><td>GLUT_CURSOR_BOTTOM_RIGHT_CORNER	</td><td>Arrow pointing to bottom-left corner.	</td></tr>
		<tr><td>GLUT_CURSOR_BOTTOM_LEFT_CORNER	</td><td>Arrow pointing to bottom-right corner.	</td></tr>
		<tr><td>GLUT_CURSOR_FULL_CROSSHAIR	</td><td>Full-screen cross-hair cursor (if possible, otherwise GLUT_CURSOR_CROSSHAIR).</td></tr>
		<tr><td>GLUT_CURSOR_NONE		</td><td>Invisible cursor.			</td></tr>
		<tr><td>GLUT_CURSOR_INHERIT		</td><td>Use parent's cursor.			</td></tr>
		</table>

		<pre>setCursor()</pre> changes the cursor image of the current window. 
		Each call requests the window system change the cursor appropriately. 
		The cursor image when a window is created is GLUT_CURSOR_INHERIT.
		The exact cursor images used are implementation dependent. The intent 
		is for the image to convey the meaning of the cursor name. For a 
		top-level window, GLUT_CURSOR_INHERIT uses the default window system 
		cursor.
	
	*/
	void setCursor(int cursor);

	/*! 
		\brief		Enter fullscreen game mode 
		\note		Window will occupy the whole screen, but will not change display mode.
	*/
	void enterGameMode();
	/*! 
		\brief		Leave fullscreen game mode
		\note		Window will receive OnReshape() event
	*/
	void leaveGameMode();
	/*! 
		\brief		Toggle fullscreen game mode
		\note		Window will receive OnReshape() event
	*/
	void toggleGameMode();
	/*! 
		\brief		Trigger a redraw 
		\note		Window will receive OnDraw() event
	*/
	void postRedisplay();
	/*! 
		\brief		Configure a timer event to occur after an elapsed time period
		\note		Window will receive OnTimer() event
	*/
	void setTimer(unsigned int msecs,unsigned char val);
	/*! 
		\brief		Configure draw events to occur at a given frequency
		\param		msec	Time between draw events in milli seconds, zero to disable
		\note		Window will receive OnDraw() events
	*/
	void setTick(unsigned int msec);
	/*! 
		\brief		Window will receive OnIdle() events, continuously
		\warning	This tends to hog the CPU
	*/
	void setIdle(bool idle);
	/*! 
		\brief		Configure whether front and back buffers should be swapped after each redraw.
		\note		Will be enabled by default if double buffering is enabled.
	*/
	void setSwapBuffers(const bool swap);

	//
	// OpenGL Frame Buffer Capture
	//

	/// Capture OpenGL RGB Buffer
	bool captureRGB    (const std::string &filename);
	/// Capture OpenGL Z Buffer
	bool captureZBuffer(const std::string &filename);
	/// Capture OpenGL Stencil Buffer
	bool captureStencil(const std::string &filename);

	//
	// Window state
	//

											/// Is the window currently open?
	         bool getOpen() const;
											/// Is the window receiving idle events?
	         bool getIdle() const;
											/// Get the window tick interval
	 unsigned int getTick() const;
											/// Is the window performing buffer swapping? 
	         bool getSwapBuffers() const;

											/// Get X position of window
			  int getX()              const;
											/// Get Y position of window
			  int getY()              const;
											/// Get width of window
			  int getWidth()          const;
											/// Get height of window
			  int getHeight()         const; 

											/// Get the number of color buffer bits
			  int getBufferSize()     const;
											/// Get the number of stencil buffer bits
			  int getStencilSize()    const;
											/// Get the number of z-buffer bits
			  int getDepthSize()      const;
											/// Get the number of red bits
			  int getRedSize()        const;
											/// Get the number of green bits
			  int getGreenSize()      const;
											/// Get the number of blue bits
			  int getBlueSize()       const;
											/// Get the number of alpha bits
			  int getAlphaSize()      const;

											/// Get the number of red accumulation buffer bits
			  int getAccumRedSize()   const;
											/// Get the number of green accumulation buffer bits
			  int getAccumGreenSize() const;
											/// Get the number of blue accumulation buffer bits
			  int getAccumBlueSize()  const;
											/// Get the number of alpha accumulation buffer bits
			  int getAccumAlphaSize() const;

											/// Is the window double buffered?
			 bool getDoubleBuffer()   const;
											/// Is the window in RGBA mode?
			 bool getRGBA()           const;
											/// Is the window in stereo mode?
			 bool getStereo()         const;
										
											/// Is this a top-level window?
			 bool getTopLevel()       const;
											/// Get number of child windows (not counting children of children)
			  int getNumChildren()    const;

											/// Get size of color index map
			  int getColormapSize()   const;
											/// Get number of samples for multisampling
			  int getNumSamples()     const;
											/// Get current cursor
			  int getCursor()         const;
										
											/// Is the shift key pressed?
			 bool getShiftModifier()  const;
											/// Is the control key pressed?
			 bool getCtrlModifier()   const;
											/// Is the alt key pressed?
			 bool getAltModifier()    const;

	//
	//
	//

	/*! 
		\brief GlutWindow menu callback messages
		\ingroup GlutMaster
	*/

	typedef enum
	{
		MENU_CLOSE = 0xff00,

		// Capture OpenGL frame buffer

		MENU_CAPTURE_RGB,		/*!< Output OpenGL RGB buffer                 */
		MENU_CAPTURE_STENCIL,		/*!< Output OpenGL Stencil buffer             */
		MENU_CAPTURE_ZBUFFER,		/*!< Output OpenGL Z-Buffer                   */

	} MenuCallbacks;

protected:  

	/// Handler for pre-display event
	virtual void OnPreDisplay();
	/// Handler for post-display event
	virtual void OnPostDisplay();
	/// Handler for pre-timer event
	virtual void OnPreTimer(unsigned char val);

								/// GLUT window ID
         int &windowID();		 
								/// GLUT window ID
   const int &windowID() const;		

	/// Current OpenGL viewport region
	GltViewport _viewport;

	/// Pop-up menu for left mouse button
	GlutMenu    _leftButtonMenu;
	/// Pop-up menu for right mouse button
	GlutMenu    _rightButtonMenu;

	/// Automatic window buffer swapping mode
	bool _swapBuffers;

	/// Reserved ID for window-tick timer events
	static const unsigned char _tickVal;

	/// Increment file index and determine filename
	std::string nextFilename();
	/// Current file index
	int _fileIndex;

private:

	/// Do double-buffer swap
	void swapBuffers();

							/// Idle flag, must be manipulated via getIdle/setIdle
	        bool _idle;
							/// Delay between update "ticks"
	unsigned int _tick;			
							/// Waiting for tick
	bool         _tickPending;
	
							/// GLUT window ID
	int _windowID;

							/// Shift keyboard modifier
	bool _shiftModifier;
							/// Control keyboard modifier
	bool _ctrlModifier;
							/// Alt keyboard modifier
	bool _altModifier;

	// These are used each time open() is called

	int          _x,_y;
	int          _width,_height;
	unsigned int _displayMode;
	bool         _gameMode;
	std::string  _title;

	// In tick-driven mode, mouse events are only
	// handled at the maximum refresh rate

	bool _mouseEvents;
	int  _mouseX,_mouseY;

	// Save the dimensions for switching 
	// between window and game mode

	bool _windowSaved;
	int  _windowX,_windowY,_windowWidth,_windowHeight;
};

#endif
