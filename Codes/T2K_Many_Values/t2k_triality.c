#include <stdio.h>
#include <math.h>

#include <globes/globes.h>

int main(int argc, char *argv[])
{
    glbInit(argv[0]);

    /* Load experiment */

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

    /* Open output file */

    FILE *fp = fopen("output.dat", "w");

    if(fp == NULL)
    {
        printf("Error opening file!\n");
        return -1;
    }

    /* Write header */

    fprintf(fp, "# E(GeV)    P2          V2          E2          Pmumu          Pmue          Pmutau\n");

    /* Energy loop */

    double E;

    for(E =0.1; E <= 2.5; E += 0.005)
    {
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

        /* Write to file */

        fprintf(fp,
                "%lf   %lf   %lf   %lf   %lf   %lf   %lf\n",
                E, P2, V2, E2, Pmumu, Pmue, Pmutau);
    }

    fclose(fp);

    printf("\nData written to output.dat\n");

    glbFreeParams(true_values);

    return 0;
}