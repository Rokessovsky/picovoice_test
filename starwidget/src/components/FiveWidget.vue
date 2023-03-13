<template>
    <div class="rating-widget">
        <span v-for="(star, index) in 5" :key="index"
            :class="{ 'star-filled': index < rating, 'star-hovered': index < hoverIndex }"
            @mouseenter="hoverRating(index + 1)" @mouseleave="hoverRating(0)" @click="submitRating(index + 1)">
            <i class="fas fa-star"></i>
        </span>
    </div>
</template>
  
<script>
export default {
    props: {
        rating: {
            type: Number,
            default: 0
        },
        productId: {
            type: String,
            required: true
        }
    },
    data() {
        return {
            hoverIndex: 0
        };
    },
    methods: {
        hoverRating(starIndex) {
            this.hoverIndex = starIndex;
        },
        submitRating(rating) {
            // TODO: send rating and productId to server to record rating
            this.$emit("rating-submitted", rating, this.productId);
        }
    }
};
</script>
  
<style>
.rating-widget {
    display: inline-flex;
}

.star-filled {
    color: #ffc107;
}

.star-hovered {
    color: #c0c0c0;
}
</style>
  