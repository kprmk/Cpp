#pragma once
#include <iostream>
#include <map>

using std::map;
using std::ostream;
using std::endl;

template <typename vertexIdType, typename edgeWeightType>
class graph
{
private:
	typedef map<vertexIdType, edgeWeightType> outgoingEdges;
	map<vertexIdType, outgoingEdges> vertexes;
		
public:
	graph()	{}
	void addVertex(const vertexIdType& name)
	{
		vertexes[name];		//ничего не присваеваем, но вершина создана
	}
	void removeVertex(const vertexIdType& name)
	{
		//удаляем саму вершину (и все исходящие вершины)
		vertexes.erase(name);
		
		//удаляем все входящие в неё рёбра
		//(для этого следует просмотреть все остальные вершины)
		for (auto& v : vertexes)
		{
			//ВАЖНО! Ссылочный типа данных!
			//При модификации данных это обязательно!
			v.second.erase(name);
		}
	}
	void addEdge(const vertexIdType& from, const vertexIdType& to, const edgeWeightType& weight)
	{
		vertexes[from][to] = weight;
		vertexes[to];		//на случай, если вершина to не существует
	}
	void removeEdge(const vertexIdType& from, const vertexIdType& to)
	{
		auto it = vertexes.find(from);
		if (it != vertexes.end())
			it->second.erase(to);
	}
	void clear()
	{
		vertexes.clear();
	}

	~graph() {}
	
	template <typename vertexIdType, typename edgeWeightType>
	friend ostream& operator<< (ostream& os, const graph<vertexIdType, edgeWeightType>& G);
};

template <typename vertexIdType, typename edgeWeightType>
ostream& operator<< (ostream& os, const graph<vertexIdType, edgeWeightType>& G)
{
	for (auto& v : G.vertexes)
	{
		os << "Vertex " << v.first << ": ";
		for (auto& e : v.second)
			os << e.first << "(" << e.second << ") ";
		os << endl;
	}
	os << endl;
	return os;
}