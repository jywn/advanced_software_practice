import torch
import numpy as np
import torch.nn.functional as F
class ClassificationNetworkColors(torch.nn.Module):
    def __init__(self):

        super().__init__()
        # setting device on GPU if available, else CPU
        device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')

        self.classes = [[-1., 0., 0.],  # left
                        [-1., 0.5, 0.], # left and accelerate
                        [-1., 0., 0.8], # left and brake
                        [1., 0., 0.],   # right
                        [1., 0.5, 0.],  # right and accelerate
                        [1., 0., 0.8],  # right and brake
                        [0., 0., 0.],   # no input
                        [0., 0.5, 0.],  # accelerate
                        [0., 0., 0.8]]  # brake

        """
        D : Network Implementation

        Implementation of the network layers. 
        The image size of the input observations is 96x96 pixels.

        Using torch.nn.Sequential(), implement each convolution layers and Linear layers
        """

        # convolution layers 



        # Linear layers (output size : 9)
        self.conv = torch.nn.Sequential(

            torch.nn.Conv2d(in_channels=3, out_channels=64, kernel_size = 5, stride = 2),
            torch.nn.LeakyReLU(negative_slope=0.2),

            torch.nn.Conv2d(in_channels=64, out_channels=32, kernel_size = 5, stride = 2),
            torch.nn.LeakyReLU(negative_slope=0.2)
        ) #96, 96, 3 or 3, 96, 96 shaping, kernel_size 확인
        # Linear layers (output size : 9)
        self.fc1 = torch.nn.Sequential(
            torch.nn.Linear(32*21*21, 256),
            torch.nn.LeakyReLU(negative_slope=0.2),
            torch.nn.Linear(256, 256),
            torch.nn.LeakyReLU(negative_slope=0.2),
            torch.nn.Linear(256, 9)
        )
        




    def forward(self, observation):
        """

        D : Network Implementation

        The forward pass of the network. 
        Returns the prediction for the given input observation.
        observation:   torch.Tensor of size (batch_size, 96, 96, 3)
        return         torch.Tensor of size (batch_size, C)

        """
        b, _, _, _ =observation.shape
        x = observation
        x = x.reshape(-1, 3, 96, 96)
        out = self.conv(x)
        out = out.view(b, -1)
        out = self.fc1(out)
        #out = F.softmax(out, dim=1)
        return out
        pass 

    def actions_to_classes(self, actions):
        """
        C : Conversion from action to classes

        For a given set of actions map every action to its corresponding
        action-class representation. Every action is represented by a 1-dim vector 
        with the entry corresponding to the class number.
        actions:        python list of N torch.Tensors of size 3
        return          python list of N torch.Tensors of size 1
        """
        action2classes = []
        for action in enumerate(actions):
            #print(action[1])
            if(torch.allclose(torch.tensor(action[1]), torch.tensor([-1, 0., 0.]))):
                action2classes.append(torch.tensor([0]))
            elif(torch.allclose(torch.tensor(action[1]), torch.tensor([-1., 0.5, 0.]))):
                action2classes.append(torch.tensor([1]))
            elif(torch.allclose(torch.tensor(action[1]), torch.tensor([-1., 0., 0.8]))):
                action2classes.append(torch.tensor([2]))
            elif(torch.allclose(torch.tensor(action[1]), torch.tensor([1., 0., 0.]))):
                action2classes.append(torch.tensor([3]))
            elif(torch.allclose(torch.tensor(action[1]), torch.tensor([1., 0.5, 0.]))):
                action2classes.append(torch.tensor([4]))
            elif(torch.allclose(torch.tensor(action[1]), torch.tensor([1.0, 0., 0.8]))):
                action2classes.append(torch.tensor([5]))
            elif(torch.allclose(torch.tensor(action[1]), torch.tensor([0., 0., 0.]))):
                action2classes.append(torch.tensor([6]))
            elif(torch.allclose(torch.tensor(action[1]), torch.tensor([0., 0.5, 0.]))):
                action2classes.append(torch.tensor([7]))
            elif(torch.allclose(torch.tensor(action[1]), torch.tensor([0., 0., 0.8]))):
                action2classes.append(torch.tensor([8]))
        print(action2classes[0].shape)
        return action2classes





        pass

    def scores_to_action(self, scores):
        """
        C : Selection of action from scores

        Maps the scores predicted by the network to an action-class and returns
        the corresponding action [steer, gas, brake].
                        C = number of classes
        scores:         python list of torch.Tensors of size C
        return          (float, float, float)
        """
        #print("hi")
        #print(self.classes[0])
        ret_actions = []
        #print(scores)
        for score in enumerate(scores):
            #print(score)
            max_idx = torch.argmax(score[1])
            if(max_idx == 0):
                return (self.classes[0])
            elif(max_idx == 1):
                return (self.classes[1])
            elif(max_idx == 2):
                return (self.classes[2])
            elif(max_idx == 3):
                return (self.classes[3])
            elif(max_idx == 4):
                return (self.classes[4])
            elif(max_idx == 5):
                return (self.classes[5])
            elif(max_idx == 6):
                return (self.classes[6])
            elif(max_idx == 7):
                return (self.classes[7])
            elif(max_idx == 8):
                return (self.classes[8])
        pass
