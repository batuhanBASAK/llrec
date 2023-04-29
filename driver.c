#include <stdio.h>
#include <stdlib.h>
#include "llrec.h"

int main()
{
    printf("llrec driver program\n");

    llrec *l = init_llrec();

    /* Add data to l */
    int i;
    for (i = 0; i < 10; i++)
        add_data(l, 10*i);

    /* Print l after adding items */
    printf("\n\nThe llrec before deletion:\n");
    print_llrec(l);


    /* Remove 3 data from l */
    for (i = 0; i < 3; i++)
        printf("%d is removed from l\n", remove_data(l));

    /* Print l after deletion items */
    printf("\n\nThe llrec after deletion:\n");
    print_llrec(l);

    
    /* Remove the rest of l */ 
    for (i = 0; i < 7; i++)
        printf("%d is removed from l\n", remove_data(l));

    /* Print l after deletion items */
    printf("\n\nThe llrec after deletion:\n");
    print_llrec(l);


    /* Add data to l again. */
    for (i = 0; i < 10; i++)
        add_data(l, 10*i);

    /* Print l after adding items */
    printf("\n\nThe llrec before deallocation:\n");
    print_llrec(l);





    /* free the memory of l */
    deallocate_llrec(&l);
    if (l == NULL)
        printf("\n\nllrec deallocated successfully.\n");
    else
        fprintf(stderr, "Error! Something went wrong during deallocation of llrec!\n");

    return 0;
}
