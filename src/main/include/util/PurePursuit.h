#ifndef PUREPURSUIT_H
#define PUREPURSUIT_H

#include<vector>



//****************************
//Coordinate struct
typedef struct coordinate
{
    double x;
    double y;
}coord_t;


class PurePursuit
{

    private:

        //Private functions
        void LoadProfile( std::string profile_filename );
        unsigned int FindClosestPoint( unsigned int curr_index );
        coord_t FindLookaheadPoint( unsigned int curr_index );
        double  CalcCurvature( coord_t aim_pt );


        //Robot Track profile Struct
        typedef struct profile_point
        {
            double x;           //[0]
            double y;           //[1]
            double velocity;    //[2]
        }profile_point_t;

        //THE PROFILE VECTOR
        std::vector<profile_point_t> m_profile; //** DOES THIS NEED TO BE A POINTER AND DYNAMIC??

        //Local Variables
        bool m_isPathDone;
        bool m_isPathError;     //Pure Pursuit algorithm calculation error (Left Path, timeout, ect)

        unsigned int m_curr_ppindex;
        unsigned int m_curr_ppindex_count;

        double m_prev_target_Lv;
        double m_prev_target_Rv;

        std::string m_profile_name;

        //File Logging
        std::ofstream *m_logfile;
        void LogfileOpen(void);
        void LogfileClose(void);
        double m_logStartTime;

    public:
        PurePursuit( std::string profile_filename );
        void PrintProfile( void );


        void PurePursuitPeriodic(void);
        void PurePursuitInit(void);
        void PurePursuitEnd(void);
        bool PurePursuitIsDone(void);
        bool PurePursuitIsError(void);

        std::string PurePursuitGetProfileName(void);
        


};

#endif // PUREPURSUIT_H
