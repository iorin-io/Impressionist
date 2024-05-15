//
// sizeChangeBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "sizeChangeBrush.h"

#include <math.h>
#define PI 3.1415

extern float frand();

SizeChangeBrush::SizeChangeBrush( ImpressionistDoc* pDoc, char* name ) :
	ImpBrush(pDoc,name), time(0.0f)
{
}

void SizeChangeBrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	int size = pDoc->getSize();


	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPointSize( (float)size );

	BrushMove( source, target );
}

void SizeChangeBrush::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	//�X���C�_�[��������

	if ( pDoc == NULL ) {
		printf( "SizeChangeBrush::BrushMove  document is NULL\n" );
		return;
	}

	int baseSize = pDoc->getSize();
	int div = 12;

	time += 0.1f;

	float waveSize = baseSize + (baseSize * 0.5f * sin(time));

	float radius = waveSize / 2.0f;
	float Ax, Ay;
	glBegin( GL_POLYGON );
	SetColor( source );
	for (int i = 0; i < div; i++) {
		Ax = target.x + radius * cos(2 * PI * i / div);
		Ay = target.y + radius * sin(2 * PI * i / div);
		glVertex2f(Ax, Ay);
	}
	glEnd();

}

void SizeChangeBrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
	glDisable(GL_BLEND);

}

