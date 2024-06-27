#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CinderProjectApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void CinderProjectApp::setup()
{
}

void CinderProjectApp::mouseDown( MouseEvent event )
{
}

void CinderProjectApp::update()
{

}

void CinderProjectApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    
    
    for (int x = 0; x < 100; x++) {
        for (int y = 0; y < 100; y++) {
            vec2 pt1(30 * x, 25 * y);
            gl::color( x * 0.1f, y * 0.1f, (x + y) * 0.02f );
            gl::drawSolidCircle(pt1, 5.0f );
        }
    }

}

CINDER_APP( CinderProjectApp, RendererGl )
