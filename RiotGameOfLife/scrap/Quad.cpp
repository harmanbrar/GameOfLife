#include "Quad.h"

Quad::Quad()
    : bottomLeftPoint(Point()), topRightPoint(Point()), isLeaf(false),
      data(nullptr), topLeft(nullptr), topRight(nullptr), bottomRight(nullptr), bottomLeft(nullptr)
      
{
}

Quad::Quad(Point topL, Point botR) 
    : bottomLeftPoint(topL), topRightPoint(botR), isLeaf(false),
    data(nullptr), topLeft(nullptr), topRight(nullptr), bottomRight(nullptr), bottomLeft(nullptr)
{
}

void Quad::insert(Cell* aNode)
{
    if (aNode == nullptr)
        return;

    // Current quad cannot contain it
    //if (!inBounds(aNode->position))
    //    return;

    //// We are at a quad of unit area
    //// We cannot subdivide this quad further
    //if ((bottomLeftPoint.x - topRightPoint.x) <= 1 &&
    //   (bottomLeftPoint.y - topRightPoint.y) <= 1)
    //{
    //    if (data == nullptr)
    //        data = aNode;
    //    return;
    //}

    //if ((bottomLeftPoint.x + topRightPoint.x) / 2 >= aNode->position.x)
    //{
    //    // Indicates topLeftTree
    //    if ((bottomLeftPoint.y + topRightPoint.y) / 2 >= aNode->position.y)
    //    {
    //        if (topLeft == nullptr)
    //        {
    //            topLeft = new Quad(Point(bottomLeftPoint.x, bottomLeftPoint.y), Point((bottomLeftPoint.x + topRightPoint.x) / 2, (bottomLeftPoint.y + topRightPoint.y) / 2));
    //        }
    //        topLeft->insert(aNode);
    //    }

    //    // Indicates botLeftTree
    //    else
    //    {
    //        if (bottomLeft == nullptr)
    //        {
    //            bottomLeft = new Quad(Point(bottomLeftPoint.x,(bottomLeftPoint.y + topRightPoint.y) / 2), Point((bottomLeftPoint.x + topRightPoint.x) / 2,topRightPoint.y));
    //        }
    //        bottomLeft->insert(aNode);
    //    }
    //}
    //else
    //{
    //    // Indicates topRightTree
    //    if ((bottomLeftPoint.y + topRightPoint.y) / 2 >= aNode->position.y)
    //    {
    //        if (topRight == nullptr)
    //        {
    //            topRight = new Quad(Point((bottomLeftPoint.x + topRightPoint.x) / 2, bottomLeftPoint.y), Point(topRightPoint.x, (bottomLeftPoint.y + topRightPoint.y) / 2));
    //        }
    //        topRight->insert(aNode);
    //    }

    //    // Indicates botRightTree
    //    else
    //    {
    //        if (bottomRight == nullptr)
    //        {
    //            bottomRight = new Quad(Point((bottomLeftPoint.x + topRightPoint.x) / 2, (bottomLeftPoint.y + topRightPoint.y) / 2), Point(topRightPoint.x, topRightPoint.y));
    //        }
    //        bottomRight->insert(aNode);
    //    }
    //}
}

Cell* Quad::search(Point aPosition)
{
    if (!inBounds(aPosition))
        return nullptr;

    // We are at a quad of unit length
    // We cannot subdivide this quad further
    if (data != nullptr)
        return data;

    if ((bottomLeftPoint.x + topRightPoint.x) / 2 >= aPosition.x)
    {
        // Indicates topLeftTree
        if ((bottomLeftPoint.y + topRightPoint.y) / 2 >= aPosition.y)
        {
            if (topLeft == nullptr)
                return nullptr;
            return topLeft->search(aPosition);
        }

        // Indicates botLeftTree
        else
        {
            if (bottomLeft == nullptr)
                return nullptr;
            return bottomLeft->search(aPosition);
        }
    }
    else
    {
        // Indicates topRightTree
        if ((bottomLeftPoint.y + topRightPoint.y) / 2 >= aPosition.y)
        {
            if (topRight == nullptr)
                return nullptr;
            return topRight->search(aPosition);
        }

        // Indicates botRightTree
        else
        {
            if (bottomRight == nullptr)
                return nullptr;
            return bottomRight->search(aPosition);
        }
    }
}

bool Quad::inBounds(Point aPosition)
{
    return (aPosition.x >= bottomLeftPoint.x &&
        aPosition.x <= topRightPoint.x &&
        aPosition.y <= bottomLeftPoint.y &&
        aPosition.y >= topRightPoint.y);
}
