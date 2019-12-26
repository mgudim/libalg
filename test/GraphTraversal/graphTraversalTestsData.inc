//NOTE:Order of neighbours of the vertex is opposite of the order in which
//edges are added. For example, if froms = {0, 0} and tos = {1, 2}, then
//0th first neighbour is 2 and then 1.
{
    GraphTraversal::Type::DFSTy,
    1,
    0,
    {0},
    {},
    {
        {0, FINISHED, -1, INVALID}
    }
},
{
    GraphTraversal::Type::DFSTy,
    2,
    1,
    {0},
    {1},
    {
        {0, DISCOVERED, 1, UNDISCOVERED},
        {1, FINISHED, -1, INVALID},
        {0, FINISHED, -1, INVALID}
    }
},
{
    GraphTraversal::Type::DFSTy,
    3,
    2,
    {0, 0},
    {1, 2},
    {
        {0, DISCOVERED, 2, UNDISCOVERED},
        {2, FINISHED, -1, INVALID},
        {0, DISCOVERED, 1, UNDISCOVERED},
        {1, FINISHED, -1, INVALID},
        {0, FINISHED, -1, INVALID}
    }
},
{
    GraphTraversal::Type::DFSTy,
    1,
    1,
    {0},
    {0},
    {
        {0, DISCOVERED, 0, DISCOVERED},
        {0, FINISHED, -1, INVALID}
    }
},
{
    GraphTraversal::Type::DFSTy,
    2,
    2,
    {0, 1},
    {1, 0},
    {
        {0, DISCOVERED, 1, UNDISCOVERED},
        {1, DISCOVERED, 0, DISCOVERED},
        {1, FINISHED, -1, INVALID},
        {0, FINISHED, -1, INVALID},
    }
},
{
    GraphTraversal::Type::DFSTy,
    3,
    3,
    {0, 0, 1},
    {1, 2, 2},
    {
        {0, DISCOVERED, 2, UNDISCOVERED},
        {2, FINISHED, -1, INVALID},
        {0, DISCOVERED, 1, UNDISCOVERED},
        {1, DISCOVERED, 2, FINISHED},
        {1, FINISHED, -1, INVALID},
        {0, FINISHED, -1, INVALID},
    }
}
