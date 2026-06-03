#include <stdio.h>
#include <math.h>

#include <globes/globes.h>

int main(int argc, char *argv[])
{
    glbInit(argv[0]);

    /* Load DUNE experiment */

    glbInitExperiment("T2K.glb",
        &glb_experiment_list[0],
        &glb_num_of_exps);
   

    printf("Experiments loaded = %d\n",
           glb_num_of_exps);

    /* Oscillation parameters */

    double theta12 = 33.76*M_PI/180.0;
    double theta13 = 8.62*M_PI/180.0;
    double theta23 = 43.29*M_PI/180.0;

    double deltacp = -90.0*M_PI/180.0;

    double dm21 = 7.537e-5;
    double dm31 = 2.511e-3;

    double density = 2.95;

    /* Allocate parameter structure */

    glb_params true_values = glbAllocParams();

    glbDefineParams(true_values,
                    theta12,
                    theta13,
                    theta23,
                    deltacp,
                    dm21,
                    dm31);

    glbSetDensityParams(true_values,
                        density,
                        GLB_ALL);

    glbSetOscillationParameters(true_values);

    /* Compute rates */

    glbSetRates();

    /* Energy = 1.2 GeV */

    double E = 1.2;
    
    /* Probabilities */

    double Pmumu =
    glbProfileProbability(0,2,2,+1,E);

    double Pmue =
    glbProfileProbability(0,2,1,+1,E);

    double Pmutau =
    glbProfileProbability(0,2,3,+1,E);

    /* Triality quantities */

    double P2 =
    2.0*(Pmumu*Pmumu +
         Pmue*Pmue +
         Pmutau*Pmutau)-1.0;

    double V2 =
    2.0*(Pmumu*Pmue +
         Pmumu*Pmutau);

    double E2 =
    2.0*(Pmumu*Pmue +
         Pmumu*Pmutau +
         2.0*Pmue*Pmutau);

    double sum = P2 + V2 + E2;

    printf("\n");
    printf("========== T2K Triality ==========\n");

    printf("Energy = %lf GeV\n\n",E);

    printf("Pmumu  = %lf\n",Pmumu);
    printf("Pmue   = %lf\n",Pmue);
    printf("Pmutau = %lf\n\n",Pmutau);

    printf("P2  = %lf\n",P2);
    printf("V2  = %lf\n",V2);
    printf("E2  = %lf\n\n",E2);

    printf("P2 + V2 + E2 = %lf\n",sum);

    printf("==================================\n");

    glbFreeParams(true_values);

    return 0;
}