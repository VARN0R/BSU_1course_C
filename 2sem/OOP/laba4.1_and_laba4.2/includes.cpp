#include "includes.h"

string getStatusName(RecognitionStatus status){
    switch (status){
        case PRESENT: return "Present";
        case NOT_PRESENT: return "Not present";
        case NOT_RECOGNIZED: return "Not Recognized"; 
    }
    return "";
}