#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <iostream>
#include <itkObject.h>

#include <itkObjectFactory.h>

namespace utils
{
class Directory : public itk::Object 
{
public:
	typedef std::string DirectoryNameType;
	typedef std::string FilenameType;
	typedef std::vector<FilenameType> FilenamesType;

	typedef Directory Self;
	typedef itk::Object Superclass;
	typedef itk::SmartPointer<Self> Pointer;
	typedef itk::SmartPointer<const Self> ConstPointer;

	itkNewMacro(Self);
	itkTypeMacro(Directory, Object);

	itkSetMacro(Directory, DirectoryNameType);
	itkGetMacro(Directory, DirectoryNameType);
	itkSetMacro(Extension, FilenameType);
	itkGetMacro(Extension, FilenameType);

	FilenamesType GetOutput() const;


	static FilenamesType GetFiles(const DirectoryNameType &dir, const FilenameType &extension="");

protected:
	Directory();
	virtual ~Directory() {}


private:
	Directory(const Self&);
	void operator=(const Self&);


	DirectoryNameType m_Directory;
	FilenameType m_Extension;

};


}


#endif