int chunk_size = total_elements / num_chunks;
int lower = 0;
int upper = chunk_size;

while (chunk not empty)
{
    // Pousser les éléments du chunk courant
    while (still elements in chunk)
    {
        if ((*list_a)->index >= lower && (*list_a)->index < upper)
        {
            pb(list_b, list_a);
            if ((*list_b)->index < lower + (chunk_size / 2))
                rb(list_b); // Optimise la remontée future
        }
        else
            ra(list_a);
    }
    lower += chunk_size;
    upper += chunk_size;
}

