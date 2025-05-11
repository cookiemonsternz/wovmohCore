class node:
    def __init__(self, name, inputs = None, outputs = None):
        self.name = name
        self.inputs = [] if inputs is None else inputs
        self.outputs = [] if outputs is None else outputs

node0 = node("node0")
node1 = node("node1", [node0])
node2 = node("node2", [node1])
node3 = node("node3", [node2])
node4 = node("node4")
node5 = node("node5", [node4], [node1, node2])

node0.outputs.append(node1)
node1.outputs.append(node2)
node2.outputs.append(node3)
node4.outputs.append(node5)

node1.inputs.append(node5)
node2.inputs.append(node5)


nodes = [node0, node1, node2, node3, node4, node5]
def init_indegrees(nodes):
    indegrees = {}
    for node in nodes:
        indegrees[node] = len(node.inputs)
    return indegrees

def print_indegrees(indegrees):
    for node, indegree in indegrees.items():
        print(f"{node.name}: {indegree}")

print_indegrees(init_indegrees(nodes))

def print_nodes(nodes):
    for node in nodes:
        print(f"{node.name}")

def decrement_indegree(node, indegrees):
    for output in node.outputs:
        indegrees[output] -= 1
    return indegrees

def khan_algorithm(nodes):
    indegrees = init_indegrees(nodes)
    queue = []
    sorted_nodes = []

    for node in nodes:
        if indegrees[node] == 0:
            queue.append(node)
    
    while queue:
        current_node = queue.pop(0)
        sorted_nodes.append(current_node)
        indegrees = decrement_indegree(current_node, indegrees)

        for output in current_node.outputs:
            if indegrees[output] == 0:
                queue.append(output)

    return sorted_nodes   

sorted_nodes = khan_algorithm(nodes)
print("Sorted nodes:")
print_nodes(sorted_nodes)