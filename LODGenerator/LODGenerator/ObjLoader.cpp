 #define cerr(x) std::cerr << x << std::endl

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::string;
using std::vector;

struct Vertex
{
	Vertex(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	int index;
	float x, y, z;
};

struct ObjMaterial 
{
	ObjMaterial(Vertex ambColor, string ambTexture, string materialName) : ambientColor(ambColor)
	{
		ambientTexture = ambTexture;
		this->materialName = materialName;
	}

	Vertex ambientColor;
	string ambientTexture;
	string materialName;
};

struct MaterialLib
{
	int index;
	vector<ObjMaterial> materials;
	
	ObjMaterial& getMaterialByName(string name)
	{
		for (ObjMaterial material : materials)
		{
			if (material.materialName == name)
			{
				return material;
			}  
		}
		return ObjMaterial(Vertex(-1.0f, -1.0f, -1.0f), nullptr, nullptr);
	}
};

struct UV
{
	int index;
	float u, v;
};
struct Face
{
	vector<Vertex> vertices;

	bool usingDefinedUVs;
	vector<UV> UVs;
	bool usingDefinedNormals;
	vector<Vertex> normals;

	vector<int> indices;

	void triangulate()
	{
		if (vertices.size() == 3) 
		{
			indices.emplace_back(vertices[0].index - 1);
			indices.emplace_back(vertices[1].index - 1);
			indices.emplace_back(vertices[2].index - 1);
		}
		else if(vertices.size() == 4)
		{
			indices.emplace_back(vertices[0].index - 1);
			indices.emplace_back(vertices[1].index - 1);
			indices.emplace_back(vertices[2].index - 1);

			indices.emplace_back(vertices[3].index - 1);
			indices.emplace_back(vertices[1].index - 1);
			indices.emplace_back(vertices[2].index - 1);
		}
	}
};


class ObjIntermediate
{
	int index;
public:

	void LoadObj(string path)
	{
		vector<Vertex> vertexList;
		vector<UV> uvList;
		vector<Vertex> normalList;
		vector<ObjMaterial> matLibList;
		
		std::ifstream fileStream;
		string tokens;
		fileStream.open(path);

		if (fileStream.fail())
		{
			cerr("Failed to Open File specified.");
			exit(1);
		}
		while (!fileStream.eof()) 
		{
			getline(fileStream, tokens);

			if (!(tokens.at(0)=='v'))
			{

			}
		//	else if ()
			//{

			//}
		}
	}

	void parseFace(string* tokens, Face& faceOut, vector<Vertex>& vertexList, vector<UV>& uvList, vector<Vertex>& normalList)
	{

	}

	void parseMaterial(string path, MaterialLib& outMaterial)
	{
		std::ifstream fileStream;
		vector<string> tokens;
		string returnLine;
		fileStream.open(path);

		int currentMaterialIndex = -1;

		if (fileStream.fail())
		{
			cerr("Failed to open file specified.");
			exit(1);
		}

	//	int currentMaterialIndex = -1;
		while(fileStream.good())
		{
			getline(fileStream, returnLine);

			if (returnLine.empty())
				getline(fileStream, returnLine);
			//	split returned string on " " store the array of strings in tokens
//			while (!returnLine._Eos)
		//	{
		//		returnLine.begin();
		//		tokens.emplace_back();
		//	}
	
			//query the first item in the array
	//			if it is equal to newmtl
	//				currentMaterialIndex++;
	//		outMaterial.OBJMaterials.emplace_back(Material());
	//		outMaterial.OBJMaterials[currentMaterialIndex].materialName = whatever the provided name was
		//		if it is equal to Ka
		//			outMaterial.OBJMaterials[currentMaterialIndex].ambientColor = whatever the provided color was
		//			~~
		//			if it is equal to map_Ka
		//				outMaterial.OBJMaterials[currentMaterialIndex].ambientTexture = whatever the provided texture path was
		}
	}
};