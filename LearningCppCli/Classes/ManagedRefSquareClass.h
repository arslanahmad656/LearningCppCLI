#pragma once
ref class ManagedRefSquareClass
{
private:
	int* size;
public:
	ManagedRefSquareClass(int size);
	~ManagedRefSquareClass();	// Managed destructor. Implementing a managed destructor is equivalent to implementing IDisposable interface and implementing its Dispose method.
								// Furthermore, the destructor automatically calls GC.SupressFinalizer method at the end.
								// In managed classes, there is no need to implement IDisposable. Simply implement the destructor.
								// Since the it is never known when or whether the CLR will call the destructor (just like it's not known in C# when or if CLR will call the Dispose method),
								// so it is best to include the clean up code in the finalizer and dispose of the object manually.
	!ManagedRefSquareClass();	// Finalizer is equivalent to overriding Object.Finalize method in C# and implementing class destructor in C#.
								// This is the method that is guaranteed to be called whenever an object is garbage collected. So any clean up should be placed in this method.
								// Furthermore, explicitly disposing of an object (which calls the IDisposable.Dispose method implemented in managed class as a managed desctructor) automatically suppress the finalizer.
								// So a call should be made to this finalizer method from the destructor.
	void CalculateArea();
};

