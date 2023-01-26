%% Image Processing System-Image Binarization  Block
G_B_GAIN = 2;
BINARIZATION_THRESHOLD = 80;
%% Image Processing System-Red Marker Detection block
CENTER_THRESHOLD = 2;

%% Image Processing System-Erosion
DISK_KERNEL = 6;
DILATE_KERNEL = 12;
%% IMAGE PROCESSING SYSTEM - Waypoints Follower block

SQUARE_KERNEL = 8;

FOV    = 1.6;  %Field of view= 2*(pi/FOV) this is a portion of the circumference

MIN_RADIUS_CROWN = 30;
MAX_RADIUS_CROWN = 55;

FRAME_SIZE_HEIGHT = 120;
FRAME_SIZE_WIDTH = 160;

COG_X = (FRAME_SIZE_HEIGHT/2);
COG_Y = (FRAME_SIZE_WIDTH/2);
%% PATH PLANNING SYSTEM-TAKE off checker block
FLAG_WAIT_FOR_HOVERING = 0;
Z_LOW = -0.9;
Z_HIGH = -1.1;
%% PATH PLANNING SYSTEM - Nonlinear Path Planner - X PLANNER && Y PLANNER - x derivativepart & y derivative part

CHANGE_DERIVATIVE_ERROR_THRESHOLD = 100;       
DERIVATIVE_GAIN = 0.002 ;
TIME_HOLD = 0.2;

%% PATH PLANNING SYSTEM - Non linear Path Planner - Z PLANNER 

DELAY_LANDING = 4;

MAX_ERROR_LANDING = 20;
%% PATH PLANNING SYSTEM - Nonlinear Path Planner/ - X PLANNER & Y PLANNER

GAIN_LANDING = 0.0022;

GAIN_TRACK = 0.0038;


