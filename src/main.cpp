#include "App.h"
#include "CompoundTrip.h"

int main(int argc, char const *argv[])
{
    // App *app = new App();
    // int result = app->Run();
    // delete app;
    // return result;

    Catalog cat;
    cat.Add(new Trip(new City("Paris"), new City("Lyon"), "Train"));
    cat.Add(new Trip(new City("Lyon"), new City("Bordeaux"), "Avion"));

    ArrayList *trips = new ArrayList();
    trips->Add(new Trip(new City("Paris"), new City("Lyon"), "Train"));
    trips->Add(new Trip(new City("Lyon"), new City("Madrid"), "Train"));
    trips->Add(new Trip(new City("Madrid"), new City("Lisbonne"), "Train"));
    CompoundTrip *tc1 = new CompoundTrip(trips);
    cat.Add(tc1);

    City a("Paris");
    City b("Lisbonne");

    ArrayList *result = cat.Search(&a, &b);
    printf("%d\n", result->Size());
    delete result;
}
