#ifndef __trigonometry_H
#define __trigonometry_H

#include "components.hpp"

void degreetoradian()
{
  double angle = 0, result = 0;
  String namestr = "Degree to Radian";

  display2layermenu(namestr, "");

  angle = GET_NUMBER_DECIMAL("Enter Angle");
  result = radians(angle);

  displayresult(namestr, result);
};

void radiantodegree()
{
  double angle = 0, result = 0;
  String namestr = "Radian to Degree";

  display2layermenu(namestr, "");

  angle = GET_NUMBER_DECIMAL("Enter Angle");
  result = degrees(angle);

  displayresult(namestr, result);
};

void sine_degrees()
{
  double angle = 0, result = 0;
  String namestr = "Sine (Degres)";

  display2layermenu(namestr, "");

  angle = GET_NUMBER_DECIMAL("Enter Angle");
  angle = fmod(angle + 180.0, 360.0) - 180.0;
  angle = radians(angle);
  result = sin(angle);

  displayresult(namestr, result);
};

void cosine_degrees()
{
  double angle = 0, result = 0;
  String namestr = "Cosine (Degres)";

  display2layermenu(namestr, "");

  angle = GET_NUMBER_DECIMAL("Enter Angle");
  angle = fmod(angle + 180.0, 360.0) - 180.0;
  angle = radians(angle);
  result = cos(angle);

  displayresult(namestr, result);
};

void tangent_degrees()
{
  double angle = 0, result = 0;
  String namestr = "Tangent (Degres)";

  display2layermenu(namestr, "");

  angle = GET_NUMBER_DECIMAL("Enter Angle");
  angle = fmod(angle + 180.0, 360.0) - 180.0;
  angle = radians(angle);
  result = tan(angle);

  displayresult(namestr, result);
};

void cosec_degrees() {
  double angle = 0, result = 0;
  String namestr = "Cosecant (Degrees)";

  display2layermenu(namestr, "");

  angle = GET_NUMBER_DECIMAL("Enter Angle");
  angle = fmod(angle + 180.0, 360.0) - 180.0;
  angle = radians(angle);
  result = 1.0 / sin(angle);

  displayresult(namestr, result);
};

void sec_degrees() {
  double angle = 0, result = 0;
  String namestr = "Secant (Degrees)";

  display2layermenu(namestr, "");

  angle = GET_NUMBER_DECIMAL("Enter Angle");
  angle = fmod(angle + 180.0, 360.0) - 180.0;
  angle = radians(angle);
  result = 1.0 / cos(angle);

  displayresult(namestr, result);
};

void cot_degrees() {
  double angle = 0, result = 0;
  String namestr = "Cotangent (Degrees)";

  display2layermenu(namestr, "");

  angle = GET_NUMBER_DECIMAL("Enter Angle");
  angle = fmod(angle + 180.0, 360.0) - 180.0;
  angle = radians(angle);
  result = 1.0 / tan(angle);

  displayresult(namestr, result);
};

void sine_radians() {
  double angle = 0, result = 0;
  String namestr = "Sine (Radians)";

  display2layermenu(namestr, "");

  angle = GET_NUMBER_DECIMAL("Enter Angle");
  angle = fmod(angle + M_PI, 2 * M_PI) - M_PI; // Using M_PI for Pi
  result = sin(angle);

  displayresult(namestr, result);
};

void cosine_radians() {
  double angle = 0, result = 0;
  String namestr = "Cosine (Radians)";

  display2layermenu(namestr, "");

  angle = GET_NUMBER_DECIMAL("Enter Angle");
  angle = fmod(angle + M_PI, 2 * M_PI) - M_PI; // Using M_PI for Pi
  result = cos(angle);

  displayresult(namestr, result);
};

void tangent_radians() {
  double angle = 0, result = 0;
  String namestr = "Tangent (Radians)";

  display2layermenu(namestr, "");

  angle = GET_NUMBER_DECIMAL("Enter Angle");
  angle = fmod(angle + M_PI, 2 * M_PI) - M_PI; // Using M_PI for Pi
  result = tan(angle);

  displayresult(namestr, result);
};

void cosec_radians() {
  double angle = 0, result = 0;
  String namestr = "Cosecant (Radians)";

  display2layermenu(namestr, "");

  angle = GET_NUMBER_DECIMAL("Enter Angle");
  angle = fmod(angle + M_PI, 2 * M_PI) - M_PI; // Using M_PI for Pi
  result = 1.0 / sin(angle);

  displayresult(namestr, result);
};

void sec_radians() {
  double angle = 0, result = 0;
  String namestr = "Secant (Radians)";

  display2layermenu(namestr, "");

  angle = GET_NUMBER_DECIMAL("Enter Angle");
  angle = fmod(angle + M_PI, 2 * M_PI) - M_PI; // Using M_PI for Pi
  result = 1.0 / cos(angle);

  displayresult(namestr, result);
};

void cot_radians() {
  double angle = 0, result = 0;
  String namestr = "Cotangent (Radians)";

  display2layermenu(namestr, "");

  angle = GET_NUMBER_DECIMAL("Enter Angle");
  angle = fmod(angle + M_PI, 2 * M_PI) - M_PI; // Using M_PI for Pi
  result = 1.0 / tan(angle);

  displayresult(namestr, result);
};



#endif