void setConveyorSpeed(int); // just a forward-declaration for now

void startConveyorBelt() {
  setConveyorSpeed(127);
}

void stopConveyorBelt() {
  setConveyorSpeed(0);
}

bool launcherHasBalls() {
  const bool ballsOnBottom = distance(senseDistanceBottomOpening) < 20;
  const bool ballsOnTop = distance(senseDistanceTopOpening) < 20;

  return ballsOnTop || ballsOnBottom;
}
